#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#define int long long

void bubble_sort(std::vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 1; j < v.size(); ++j) {
            if (v[j - 1] > v[j]) {
                std::swap(v[j - 1], v[j]);
            }
        }
    }
}

signed main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    bubble_sort(v);

    for (auto i : v) {
        std::cout << i << ' ';
    }

    return 0;
}
