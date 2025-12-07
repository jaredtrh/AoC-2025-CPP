#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    
    vector<string> grid;

    string line;
    while (getline(cin, line)) {
        grid.push_back(move(line));
    }
    int n = grid.size();
    int m = grid[0].size();
    
    vector<long long> dp(m, 1);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 1; j < m - 1; ++j) {
            if (grid[i][j] == '^') {
                dp[j] = dp[j - 1] + dp[j + 1];
            }
        }
    }
    cout << dp[grid[0].find('S')] << "\n";
}