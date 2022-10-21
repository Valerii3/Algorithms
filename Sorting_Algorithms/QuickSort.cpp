#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

#define int long long

void partition(int l, int r, int x, std::vector<int> &v, int &i, int &j) {
    i = l, j = r;
    while (i <= j) {
        while (v[i] < x)
            i++;
        while (v[j] > x)
            j--;
        if (i <= j)
            std::swap(v[i++], v[j--]);
    }
}

void quicksort(int l, int r, std::vector<int> &v) {
    if (l >= r)
        return;
    int i, j;
    int x = v[(r + l) / 2];
    partition(l, r, x, v, i, j);
    quicksort(l, j, v);
    quicksort(i, r, v);
}

signed main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    int l = 0, r = n - 1;
    quicksort(l, r, v);
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << ' ';
    }
}
