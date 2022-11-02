#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#define int long long

bool binary_search(const std::vector<int> &v, int req) {
    int l = 0, r = v.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (v[m] == req) {
            return true;
        } else if (v[m] < req) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return false;
}

int lower_bound(const std::vector<int> &v, int k) {
    int l = -1, r = v.size();
    while (l < r - 1) {
        int m = (r + l) / 2;
        if (v[m] <= k) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

int upper_bound(const std::vector<int> &v, int k) {
    int l = -1, r = v.size();
    while (l < r - 1) {
        int m = (r + l) / 2;
        if (v[m] < k) {
            l = m;
        } else {
            r = m;
        }
    }
    return r;
}

signed main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    for (int i = 0; i < k; ++i) {
        int req;
        std::cin >> req;
        std::cout << upper_bound(v, req) + 1 << ' ';
        std::cout << lower_bound(v, req) + 1 << '\n';
    }

    return 0;
}
