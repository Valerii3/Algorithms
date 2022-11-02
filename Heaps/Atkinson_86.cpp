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

unsigned int a, b;

const int max = 100001;

std::set<int> new_lvl{1,   3,    7,    15,   31,   63,    127,   255,
                      511, 1023, 2047, 4095, 8192, 16383, 32767, 65535};

int parent(int ind) {
  int t = (ind - 1) / 2;
  return (t - 1) / 2;
}

struct Heap {
private:
  int *v;
  int heap_size;

  void sift_up(int ind) {
    if (ind == 0)
      return;
    if (new_lvl.find(ind) !=
        new_lvl
            .end()) { // need to check values like 1,3,7 (2 ^ n - 1 for any n)
      if ((int)log2(ind + 2) % 2 != 0) {  // max
        if (v[ind] >= v[(ind - 1) / 2]) { // same invariant
          while (ind > 0 && v[ind] > v[parent(ind)] &&
                 (int)log2(parent(ind)) % 2 != 0) {
            std::swap(v[ind], v[parent(ind)]);
            ind = parent(ind);
          }
        } else {
          std::swap(v[ind], v[(ind - 1) / 2]);
          ind = (ind - 1) / 2;
          while (ind > 0 && v[ind] > v[parent(ind)]) {
            std::swap(v[ind], v[parent(ind)]);
            ind = parent(ind);
          }
        }
      } else { // min
        if (v[ind] <= v[(ind - 1) / 2]) {
          while (ind > 0 && v[ind] < v[parent(ind)]) {
            std::swap(v[ind], v[parent(ind)]);
            ind = (ind - 1) / 4;
          }
        } else {
          std::swap(v[ind], v[(ind - 1) / 2]);
          ind = (ind - 1) / 2;
          while (ind > 0 && v[ind] < v[parent(ind)]) {
            std::swap(v[ind], v[parent(ind)]);
            ind = (ind - 1) / 4;
          }
        }
      }
    } else { // новая ветка
      if ((int)log2(ind + 1) % 2 != 0) {
        if (v[ind] >= v[(ind - 1) / 2]) {
          while (ind > 0 && v[ind] > v[parent(ind)] &&
                 (int)log2(parent(ind)) % 2 != 0) {
            std::swap(v[ind], v[parent(ind)]);
            ind = parent(ind);
          }
        } else {
          std::swap(v[ind], v[(ind - 1) / 2]);
          ind = (ind - 1) / 2;
          while (ind > 0 && v[ind] > v[parent(ind)]) {
            std::swap(v[ind], v[parent(ind)]);
            ind = parent(ind);
          }
        }
      } else {
        if (v[ind] <= v[(ind - 1) / 2]) {
          while (ind > 0 && v[ind] < v[parent(ind)]) {
            std::swap(v[ind], v[parent(ind)]);
            ind = parent(ind);
          }
        } else {
          std::swap(v[ind], v[(ind - 1) / 2]);
          ind = (ind - 1) / 2;
          while (ind > 0 && v[ind] < v[parent(ind)]) {
            std::swap(v[ind], v[parent(ind)]);
            ind = parent(ind);
          }
        }
      }
    }
  }

  void sift_down(int ind, int type) {

    if (type == 0) {
      int min = 1e18;
      int min_ind = 0;
      for (int i = 0; i < 4; ++i) {
        if (4 * ind + 3 + i >= heap_size) {
          break;
        }
        if (v[ind] > v[4 * ind + 3 + i] && v[4 * ind + 3 + i] < min) {

          min_ind = 4 * ind + 3 + i;
          min = v[min_ind];
        }
      }

      if (min_ind != 0) {

        std::swap(v[ind], v[min_ind]);
        ind = min_ind;
        if (v[ind] > v[(ind - 1) / 2]) {
          std::swap(v[ind], v[(ind - 1) / 2]);
        }
        sift_down(ind, type);
      }
    } else {
      int max = -1;
      int max_ind = 0;
      for (int i = 0; i < 4; ++i) {
        if (4 * ind + 3 + i >= heap_size) {
          break;
        }
        if (v[ind] < v[4 * ind + 3 + i] && v[4 * ind + 3 + i] > max) {
          max_ind = 4 * ind + 3 + i;
          max = v[max_ind];
        }
      }
      if (max_ind != 0) {
        std::swap(v[ind], v[max_ind]);
        ind = max_ind;
        if (v[ind] < v[(ind - 1) / 2]) {
          std::swap(v[ind], v[(ind - 1) / 2]);
        }
        sift_down(ind, type);
      }
    }
  }

public:
  Heap() : v(new int[max]), heap_size(0) {}

  void insert(int num) {
    v[heap_size] = num;
    sift_up(heap_size);
    heap_size++;
  }

  int extract_min() {
    int min = v[0];
    if (heap_size == 3) {
      if (v[1] < v[2]) {
        std::swap(v[1], v[2]);
      }
    }
    std::swap(v[0], v[heap_size - 1]);
    heap_size--;
    sift_down(0, 0);

    return min;
  }

  int extract_max() {
    if (heap_size == 1) {
      heap_size--;
      return v[0];
    } else if (heap_size == 2) {
      heap_size--;
      return v[1];
    }
    int max;
    if (v[1] > v[2]) {
      max = v[1];
      std::swap(v[1], v[heap_size - 1]);
      heap_size--;
      sift_down(1, 1);
    } else {
      max = v[2];
      std::swap(v[2], v[heap_size - 1]);
      heap_size--;
      sift_down(2, 1);
    }
    return max;
  }
};

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
  Heap heap;
  while (n--) {
    std::string s;
    std::cin >> s;
    if (s == "GetMin") {
      std::cout << "Min " << heap.extract_min() << '\n';

    } else if (s == "GetMax") {
      std::cout << "Max " << heap.extract_max() << '\n';

    } else {
      s = parse(s);
      int x = 0;
      for (int i = 0; i < s.size(); ++i) {
        x = x * 10 + (s[i] - '0');
      }
      heap.insert(x);
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
