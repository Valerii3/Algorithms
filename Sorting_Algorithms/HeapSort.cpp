#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

#define int long long

void sift_up(std::vector<int> &a, int ind) {
    while (ind > 0 && a[ind] < a[(ind - 1) / 2]) {
        std::swap(a[ind], a[(ind - 1) / 2]);
        ind = (ind - 1) / 2;
    }
}

void sift_down(std::vector<int> &a, int &n) {
    std::swap(a[0], a[n - 1]);
    n--;
    int i = 0;
    while (2 * i + 1 < n) {
        int j = 2 * i + 1;
        if (2 * i + 2 < n && a[2 * i + 2] < a[j]) {
            j = 2 * i + 2;
        }
        if (a[j] >= a[i]) {
            break;
        }
        std::swap(a[i], a[j]);
        i = j;
    }
    //  return a[a.size() - 1];
}

void Heapsort(std::vector<int> &a, int n) {
    for (int i = 0; i < a.size(); ++i) {
        sift_up(a, i);
    }

    for (int i = 0; i < a.size(); ++i) {
        sift_down(a, n);
    }
}

signed main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    Heapsort(v, n);
    for (int i = n - 1; i >= 0; --i) {
        std::cout << v[i] << ' ';
    }
}
