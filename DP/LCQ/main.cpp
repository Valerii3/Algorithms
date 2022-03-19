#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

long long max(long long x, long long y) {
    if (x > y)
        return x;
    return y;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int a, b, c;
    std::cin >> a;
    std::vector<int> vec_a(a);
    for (int i = 0; i < a; ++i) {
        std::cin >> vec_a[i];
    }
    std::cin >> b;
    std::vector<int> vec_b(b);
    for (int i = 0; i < b; ++i) {
        std::cin >> vec_b[i];
    }
    std::cin >> c;
    std::vector<int> vec_c(c);
    for (int i = 0; i < c; ++i) {
        std::cin >> vec_c[i];
    }

    std::vector<std::vector<std::vector<int>>> dp(
        a + 1,
        std::vector<std::vector<int>>(b + 1, std::vector<int>(c + 1, 0)));
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            for (int k = 1; k <= c; ++k) {
                if (vec_a[i - 1] == vec_b[j - 1] and
                    vec_b[j - 1] == vec_c[k - 1]) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                } else {
                    dp[i][j][k] = max(max(dp[i][j - 1][k], dp[i - 1][j][k]),
                                      dp[i][j][k - 1]);
                }
            }
        }
    }
    std::cout << dp[a][b][c];
    return 0;
}
