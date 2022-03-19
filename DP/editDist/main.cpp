

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::string s1, s2;

long long max(long long x, long long y) {
    if (x > y)
        return x;
    return y;
}
std::vector<std::vector<long long>> a(250, std::vector<long long>(250, -1));

long long min(int x, int y) {
    if (x < y)
        return x;
    return y;
}

long long rec(long long i, long long j) {
    if (i == 0 or j == 0) {
        return max(i, j);
    }
    if (a[i][j] != -1) {
        return a[i][j];
    }
    if (s1[i - 1] == s2[j - 1]) {
        return a[i][j] = rec(i - 1, j - 1);
    }
    return a[i][j] =
               1 + min(min(rec(i, j - 1), rec(i - 1, j)), rec(i - 1, j - 1));
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> s1 >> s2;

    std::cout << rec(s1.size(), s2.size());
    return 0;
}
