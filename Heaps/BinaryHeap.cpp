#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

#define int long long

const int max = 100001;

struct Heap {  // heap with max in root (if you want to make min heap, just
               // replace > on <)
private:
    int *v;
    int heap_size;

    void sift_up(int ind) {
        while (
            ind > 0 &&
            v[ind] >
                v[(ind - 1) / 2]) {  // for min heap replace second sign > on <
            std::swap(v[ind], v[(ind - 1) / 2]);
            ind = (ind - 1) / 2;
        }
    }

    void sift_down(int ind) {
        while (2 * ind + 1 < heap_size) {
            int j = 2 * ind + 1;
            if (2 * ind + 2 < heap_size &&
                v[2 * ind + 2] >
                    v[j]) {  // for min heap replace second sign > on <
                j = 2 * ind + 2;
            }
            if (v[j] < v[ind]) {  // // for min heap < on >
                break;
            }
            std::swap(v[ind], v[j]);
            ind = j;
        }
    }

public:
    Heap() : v(new int[max]), heap_size(0) {
    }

    void insert(int num) {
        v[heap_size] = num;
        sift_up(heap_size);
        heap_size++;
    }

    int extract_min() {
        int min = v[0];
        std::swap(v[0], v[heap_size - 1]);
        heap_size--;
        sift_down(0);
        return min;
    }
};

signed main() {
    Heap heap;
    int n;
    std::cin >> n;
    while (n--) {
        int type;
        std::cin >> type;
        if (type == 0) {
            int num;
            std::cin >> num;
            heap.insert(num);
        } else {
            int res = heap.extract_min();
            std::cout << res << '\n';
        }
    }
}
