#include <stdlib.h>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstring>
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
//#include "optimization.h"

std::vector<int> ans;

void dfs(int v,
         const std::vector<std::vector<int>> &g,
         std::vector<int> &used) {
    used[v] = 1;
    for (auto i : g[v]) {
        if (used[i] == 0) {
            dfs(i, g, used);
        }
    }
    ans.push_back(v);
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, m, x, y;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);

    for (int i = 0; i < m; ++i) {
        std::cin >> x >> y;
        g[x - 1].push_back(y - 1);
    }

    std::vector<int> used(n, 0);
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            dfs(i, g, used);
        }
    }

    std::reverse(ans.begin(), ans.end());
    used.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        used[ans[i]] = 1;
        bool flag = false;
        for (auto j : g[ans[i]]) {
            if (used[j] != 0) {
                std::cout << "NO";
                return 0;
            }
            if (i != n - 1) {
                if (j == ans[i + 1]) {
                    flag = true;
                }
            }
        }
        if (flag == false and i != n - 1) {
            std::cout << "NO";
            return 0;
        }
    }
    std::cout << "YES" << '\n';
    for (auto i : ans) {
        std::cout << i + 1 << ' ';
    }

    return 0;
}