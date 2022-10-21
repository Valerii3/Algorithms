#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#define int long long

void selection_sort(std::vector<int> &v) {
    int len = v.size();
    for (int i = len - 1; i >= 0; --i) {
        int max = i;
        for (int j = i; j >= 0; --j) {
            if (v[j] > v[max]) {
                max = j;
            }
        }
        std::swap(v[i], v[max]);
    }
}

signed main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    selection_sort(v);
    for (auto i : v) {
        std::cout << i << ' ';
    }
}