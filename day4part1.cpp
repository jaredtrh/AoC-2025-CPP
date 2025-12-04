#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    
    vector<string> grid;
    string line;
    while (getline(cin, line)) {
        grid.push_back(line);
    }
    int n = grid.size();
    int m = grid[0].size();

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != '@') continue;
            int cnt = -1;
            for (int ai = max(0, i - 1); ai <= min(n - 1, i + 1); ++ai) {
                for (int aj = max(0, j - 1); aj <= min(m - 1, j + 1); ++aj) {
                    cnt += grid[ai][aj] == '@';
                }
            }
            ans += cnt < 4;
        }
    }
    cout << ans << "\n";
}