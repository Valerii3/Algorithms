#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

template<typename T>
void swap(T *a, T *b) {   // implementation of std::swap
  T tmp = *a;
  *a = *b;
  *b = tmp;
}

template<typename T>
void Insertion(std::vector<T> &arr) {   // sorting
  for (int i = 0; i < static_cast<int>(arr.size()); i++) {
    int j = i;
    while (j > 0 && arr[j] < arr[j - 1]) {
      swap(&arr[j], &arr[j - 1]);
      j--;
    }
  }
}

template<typename T>
void print(const std::vector<T> &arr){
    for (auto num : arr) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}

int main() {
  std::vector<int> arr1 = {3, 5, 9, 2, 5, 6, 12, 1};
  std::vector<double> arr2 = {3.1, 5.5, 9.2, 2.6, 5.4, 6.23, 12.7, 1.1};  // initialize vector

  Insertion(arr1);
  Insertion(arr2);

  assert((arr1 == std::vector<int>{1, 2, 3, 5, 5, 6, 9, 12}));  // check
  assert((arr2 == std::vector<double>{1.1, 2.6, 3.1, 5.4, 5.5, 6.23, 9.2, 12.7}));


  print(arr1);
  print(arr2);

  return 0;
}
