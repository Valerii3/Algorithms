#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#define int long long

int max_s = N;  // replace N with the count of different numbers in your array

int count[max_s];
int count_min[max_s];

void count_sort(std::vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] < 0) {
            count_min[-v[i]]++;
        } else {
            count[v[i]]++;
        }
    }
    int ind = 0;

    for (int x = max_s; x >= 0; --x) {
        while (count_min[x]--) {
            v[ind] = -x;
            ind++;
        }
    }

    for (int x = 0; x < max_s; ++x) {
        while (count[x]--) {
            v[ind] = x;
            ind++;
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
    count_sort(v);

    for (auto i : v) {
        std::cout << i << ' ';
    }
    return 0;
}
