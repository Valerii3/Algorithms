#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

std::vector<int> Merge(const std::vector<int> &arr1, const std::vector<int> &arr2){
    int len1 = static_cast<int>(arr1.size());
    int len2 = static_cast<int>(arr2.size());
    int i = 0, j = 0;

    std::vector<int> tmp;

    while (i < len1 || j < len2){
        if (j == len2 || (i < len1 && arr1[i] < arr2[j])){
            tmp.push_back(arr1[i]);
            i++;
        } else {
            tmp.push_back(arr2[j]);
            j++;
        }
    }

    return tmp;
}

int main() {
    std::vector<int> arr1 = {1, 2, 6, 7, 9, 11};   // should be sorted
    std::vector<int> arr2 = {2, 3, 4, 7, 8, 9, 14, 15};

    std::vector<int> result = Merge(arr1, arr2);

    assert((result == std::vector<int>{1, 2, 2, 3, 4, 6, 7, 7, 8, 9, 9, 11, 14, 15}));

    for (auto num : result) {
        std::cout << num << ' ';
    }

    return 0;
}

