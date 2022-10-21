#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

template <typename T>
void swap(T *a, T *b) {  // implementation of std::swap
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

template <typename T>
void print(const std::vector<T> &arr) {
    for (auto num : arr) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}

template <typename T>
void Insertion(std::vector<T> &arr) {  // sorting
    for (int i = 0; i < static_cast<int>(arr.size()); i++) {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1]) {
            swap(&arr[j], &arr[j - 1]);
            j--;
        }
        if (j != i)
            print(arr);
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    Insertion(a);

    print(a);

    return 0;
}
