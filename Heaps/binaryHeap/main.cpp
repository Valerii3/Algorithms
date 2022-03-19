#include <assert.h>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

const int MAX_SIZE = 200000;

class Heap {
public:
    Heap() {
        a = new int[MAX_SIZE];
        heap_size = 0;
    }
    void insert(int value) {
        a[heap_size] = value;
        shift_up(heap_size);
        heap_size++;
    }

    int extract_min() {
        int min = a[0];
        std::swap(a[0], a[heap_size - 1]);
        heap_size--;
        shift_down(0);
        return min;
    }

private:
    int heap_size;
    int *a;
    void shift_up(int ind) {
        int par = (ind - 1) / 2;
        while (a[par] > a[ind]) {
            std::swap(a[par], a[ind]);
            ind = par;
            par = (ind - 1) / 2;
        }
    }
    void shift_down(int ind) {
        while (2 * ind + 1 < heap_size) {
            int l = 2 * ind + 1;
            int r = 2 * ind + 2;
            int next = l;
            if (r < heap_size and a[r] < a[l]) {
                next = r;
            }
            if (a[ind] > a[next]) {
                std::swap(a[next], a[ind]);
                ind = next;
            } else {
                return;
            }
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    Heap heap;
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        char type = '0';
        std::cin >> type;
        if (type == '+') {
            int value = 0;
            std::cin >> value;
            heap.insert(value);
        } else {
            std::cout << heap.extract_min() << '\n';
        }
    }
    return 0;
}