#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#define int long long

const int max = 200000;

std::unordered_map<int, std::pair<int, int>> m;  // first min second max

struct Node {
    int value;
    int id;
    int index;
};

struct MinHeap;

struct MaxHeap {
private:
    Node *v;
    int heap_size;

    void sift_up(Node x) {
        int ind = x.index;
        while (ind > 0 && v[ind].value > v[(ind - 1) / 2].value) {
            int tmp = v[ind].index;

            v[ind].index = (ind - 1) / 2;
            v[(ind - 1) / 2].index = tmp;

            std::swap(v[ind], v[(ind - 1) / 2]);
            m[v[ind].id].second = v[ind].index;
            m[v[(ind - 1) / 2].id].second = v[(ind - 1) / 2].index;
            ind = (ind - 1) / 2;
        }
    }

    void sift_down(Node x) {
        int ind = x.index;

        while (2 * ind + 1 < heap_size) {
            int j = 2 * ind + 1;
            if (2 * ind + 2 < heap_size && v[2 * ind + 2].value > v[j].value) {
                j = 2 * ind + 2;
            }
            if (v[j].value < v[ind].value) {
                // // for min heap < on >
                break;
            }

            v[ind].index = j;
            v[j].index = ind;
            std::swap(v[ind], v[j]);
            m[v[ind].id].second = v[ind].index;
            m[v[j].id].second = v[j].index;
            ind = j;
        }
    }

public:
    MaxHeap() : v(new Node[max]), heap_size(0) {
    }

    void insert(Node num) {
        v[heap_size].value = num.value;
        v[heap_size].index = heap_size;
        v[heap_size].id = num.id;
        m[num.id].second = heap_size;
        sift_up(v[heap_size]);
        heap_size++;
    }

    int extract_max(MinHeap &minheap);

    void del(int ind) {
        v[ind].index = heap_size - 1;
        v[heap_size - 1].index = ind;
        std::swap(v[ind], v[heap_size - 1]);

        m[v[ind].id].second = v[ind].index;
        m[v[heap_size - 1].id].second = v[heap_size - 1].index;

        heap_size--;
        if (ind == 0) {
            return;
        }
        if (v[ind].value > v[(ind - 1) / 2].value) {
            sift_up(v[ind]);
        } else {
            sift_down(v[ind]);
        }
    }
};

struct MinHeap {
private:
    Node *v;
    int heap_size;

    void sift_up(Node x) {
        int ind = x.index;
        while (ind > 0 && v[ind].value < v[(ind - 1) / 2].value) {
            int tmp = v[ind].index;

            v[ind].index = (ind - 1) / 2;
            v[(ind - 1) / 2].index = tmp;

            std::swap(v[ind], v[(ind - 1) / 2]);
            m[v[ind].id].first = v[ind].index;
            m[v[(ind - 1) / 2].id].first = v[(ind - 1) / 2].index;
            ind = (ind - 1) / 2;
        }
    }

    void sift_down(Node x) {
        int ind = x.index;

        while (2 * ind + 1 < heap_size) {
            int j = 2 * ind + 1;
            if (2 * ind + 2 < heap_size && v[2 * ind + 2].value < v[j].value) {
                j = 2 * ind + 2;
            }
            if (v[j].value > v[ind].value) {
                break;
            }

            v[ind].index = j;
            v[j].index = ind;
            std::swap(v[ind], v[j]);
            m[v[ind].id].first = v[ind].index;
            m[v[j].id].first = v[j].index;
            ind = j;
        }
    }

public:
    MinHeap() : v(new Node[max]), heap_size(0) {
    }

    void insert(Node num) {
        v[heap_size].value = num.value;
        v[heap_size].index = heap_size;
        v[heap_size].id = num.id;
        m[num.id].first = heap_size;
        sift_up(v[heap_size]);
        heap_size++;
    }

    int extract_min(MaxHeap &maxheap) {
        int min = v[0].value;

        int id = v[0].id;

        int ind_in_maxheap = m[id].second;

        maxheap.del(ind_in_maxheap);

        v[0].index = heap_size - 1;
        v[heap_size - 1].index = 0;

        std::swap(v[0], v[heap_size - 1]);
        m[v[0].id].first = v[0].index;
        m[v[heap_size - 1].id].first = v[heap_size - 1].index;

        heap_size--;
        sift_down(v[0]);

        return min;
    }

    void del(int ind) {
        v[ind].index = heap_size - 1;
        v[heap_size - 1].index = ind;
        std::swap(v[ind], v[heap_size - 1]);
        m[v[ind].id].first = v[ind].index;
        m[v[heap_size - 1].id].first = v[heap_size - 1].index;
        heap_size--;
        if (ind == 0) {
            return;
        }
        if (v[ind].value < v[(ind - 1) / 2].value) {
            sift_up(v[ind]);
        } else {
            sift_down(v[ind]);
        }
    }
};

int MaxHeap::extract_max(MinHeap &minheap) {
    int max = v[0].value;

    int id = v[0].id;

    int ind_in_min_heap = m[id].first;

    minheap.del(ind_in_min_heap);

    v[0].index = heap_size - 1;
    v[heap_size - 1].index = 0;
    std::swap(v[0], v[heap_size - 1]);
    m[v[0].id].second = v[0].index;
    m[v[heap_size - 1].id].second = v[heap_size - 1].index;

    heap_size--;
    sift_down(v[0]);

    return max;
}

std::string parse(const std::string &s) {
    std::string tmp = "";
    bool flag = false;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ')') {
            break;
        }
        if (flag) {
            tmp += s[i];
        }
        if (s[i] == '(') {
            flag = true;
        }
    }
    return tmp;
}

void solve() {
    int n;
    std::cin >> n;

    MaxHeap maxheap;
    MinHeap minheap;
    while (n--) {
        std::string s;
        std::cin >> s;
        if (s == "GetMin") {
            std::cout << minheap.extract_min(maxheap) << '\n';

        } else if (s == "GetMax") {
            std::cout << maxheap.extract_max(minheap) << '\n';

        } else {
            s = parse(s);
            int x = 0;
            for (int i = 0; i < s.size(); ++i) {
                x = x * 10 + (s[i] - '0');
            }

            minheap.insert(Node{x, n, 1});
            maxheap.insert(Node{x, n, 1});
        }
    }
}

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int test = 1;
    //  std::cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
