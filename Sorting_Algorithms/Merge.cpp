#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

#define int long long

void Merge(std::vector<int> &a, int l, int m, int r){
    std::vector<int> left, right;
    for (int i = l; i < m; ++i) {
        left.push_back(a[i]);
    }
    for (int i = m; i < r; ++i) {
        right.push_back(a[i]);
    }

    int len1 = left.size(), len2 = right.size();

    int i = 0, j = 0;
    std::vector<int> tmp;
    while (i < len1 || j < len2){
        if (j == len2 || (i < len1 && left[i] < right[j])){
            tmp.push_back(left[i]);
            i++;
        } else {
            tmp.push_back(right[j]);
            j++;
        }
    }
    for (int k = 0; k < tmp.size(); ++k) {
        a[k + l] = tmp[k];
    }

}

void merge_sort(std::vector<int> &a, int l, int r){
    if (r - l <= 1){
        return;
    }
    int m = (r + l) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m, r);
    Merge(a, l, m, r);
}

signed main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    int l = 0, r = n;
    merge_sort(v, l, r);
    for (auto num : v) {
        std::cout << num << ' ';
    }

    return 0;
}

