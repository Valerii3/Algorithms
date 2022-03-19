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

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, S;
    std::cin >> S >> n;
    std::vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> ans[i];
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(S + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= S; ++j) {
            if (ans[i] <= j) {
                dp[i][j] = dp[i - 1][j] or dp[i - 1][j - ans[i]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (int k = S; k >= 0; k--) {
        if (dp[n][k] == 1) {
            std::cout << k;
            return 0;
        }
    }
}
