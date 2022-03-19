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

uint32_t a, b;

void Merge_Sort(int *array,
                int array_size,
                unsigned long long *number_of_inversitions) {
    if (array_size <= 1)
        return;

    int middle = array_size / 2;
    int left_size = middle;
    int right_size = array_size - middle;
    int *left = array;
    int *right = array + left_size;

    Merge_Sort(left, left_size, number_of_inversitions);
    Merge_Sort(right, right_size, number_of_inversitions);

    int left_index = 0;
    int right_index = 0;
    int index = 0;
    int *temp_array = new int[array_size];
    while (left_index < left_size and right_index < right_size) {
        if (left[left_index] <= right[right_index])
            temp_array[index++] = left[left_index++];
        else {
            temp_array[index++] = right[right_index++];
            *number_of_inversitions += left_size - left_index;
        }
    }

    while (left_index < left_size)
        temp_array[index++] = left[left_index++];
    while (right_index < right_size)
        temp_array[index++] = right[right_index++];

    for (int i = 0; i < array_size; i++)
        array[i] = temp_array[i];
    delete[] temp_array;
}

uint32_t cur = 0;
uint32_t nextRand24() {
    cur = cur * a + b;
    return cur >> 8;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, m;
    std::cin >> n >> m >> a >> b;
    int *mas = new int[n];
    for (int i = 0; i < n; ++i) {
        mas[i] = nextRand24() % m;
    }

    unsigned long long inv_count = 0;
    Merge_Sort(mas, n, &inv_count);
    std::cout << inv_count;
    
    return 0;
}