
#include <algorithm>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

long long min_sum(long long a, long long b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

long long z_pl(long long a, long long b, long long sum) {
    if (a + b > sum) {
        return a + b;
    }
    return sum;
}

long long z_mi(long long a, long long b, long long sum) {
    if (a + b < sum) {
        return a + b;
    }
    return sum;
}

long long t_pl(long long a, long long b, long long sum) {
    if (a - b > sum) {
        return a - b;
    }
    return sum;
}

long long t_mi(long long a, long long b, long long sum) {
    if (a - b < sum) {
        return a - b;
    }
    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    ///////////// ввод заполнение t z //////////////
    long long n;
    long long max_t = -5 * 1e9, max_z = -5 * 1e9, min_t = 5 * 1e9,
              min_z = 5 * 1e9;
    std::vector<std::pair<long long, long long>> cord;
    std::cin >> n;
    long long x, y;
    for (int i = 0; i < n; i++) {
        std::cin >> x >> y;
        cord.push_back({x, y});
        max_z = z_pl(x, y, max_z);
        min_z = z_mi(x, y, min_z);
        max_t = t_pl(x, y, max_t);
        min_t = t_mi(x, y, min_t);
    }

    double main_z = (max_z + min_z);
    double main_t = (max_t + min_t);
    double main_x = (main_z + main_t) / 4;
    double main_y = (main_z - main_t) / 4;

    long long sum_xy_up = -1, sum_xy_d = -1, sum_xd_yu = -1, sum_xu_yd = -1;
    long long upx = ceil(main_x), upy = ceil(main_y), dx = floor(main_x),
              dy = floor(main_y);
    for (int i = 0; i < cord.size(); i++) {
        sum_xy_up = std::max(
            abs(upx - cord[i].first) + abs(upy - cord[i].second), sum_xy_up);
        sum_xy_d = std::max(abs(dx - cord[i].first) + abs(dy - cord[i].second),
                            sum_xy_d);
        sum_xd_yu = std::max(
            abs(dx - cord[i].first) + abs(upy - cord[i].second), sum_xd_yu);
        sum_xu_yd = std::max(
            abs(upx - cord[i].first) + abs(dy - cord[i].second), sum_xu_yd);
    }

    long long res =
        min_sum(min_sum(sum_xd_yu, sum_xu_yd), min_sum(sum_xy_up, sum_xy_d));
    if (res == sum_xy_d) {
        std::cout << dx << ' ' << dy;
    } else if (res == sum_xy_up) {
        std::cout << upx << ' ' << upy;
    } else if (res == sum_xu_yd) {
        std::cout << upx << ' ' << dy;
    } else {
        std::cout << dx << ' ' << upy;
    }

    return 0;
}