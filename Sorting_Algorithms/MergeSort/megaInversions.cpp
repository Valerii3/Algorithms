

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define int long long

std::vector<std::pair<int, int>> dop;
void Merge_vectors(int l, int r, int m, std::vector<std::pair<int, int>> &a) {
    int left = l, right = m;
    std::vector<std::pair<int, int>> ans;
    while (left < m and right < r) {
        if (a[left].first < a[right].first) {
            ans.push_back(a[left]);
            dop[a[left].second].second += right - m;
            left++;
        } else {
            dop[a[right].second].first += m - left;
            ans.push_back(a[right]);
            right++;
        }
    }

    while (left < m) {
        ans.push_back(a[left]);
        dop[a[left].second].second += right - m;
        left++;
    }
    while (right < r) {
        ans.push_back(a[right]);
        dop[a[right].second].first += m - left;
        right++;
    }

    for (int i = l; i < r; ++i) {
        a[i] = ans[i - l];
    }
}

void Merge_sort(int l, int r, std::vector<std::pair<int, int>> &a) {
    if (l < r - 1) {
        int m = (l + r) / 2;
        Merge_sort(l, m, a);
        Merge_sort(m, r, a);
        Merge_vectors(l, r, m, a);
    }
}

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, l = 0;
    std::cin >> n;
    int r = n;
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].first;
        a[i].second = i;
    }
    dop.resize(n);
    Merge_sort(l, r, a);

    unsigned long long sum = 0;
    for (auto i : dop) {
        sum += i.first * i.second;
    }
    std::cout << sum;
    return 0;
}
