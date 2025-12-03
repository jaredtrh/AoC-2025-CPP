#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    const int B = 12;

    long long ans = 0;
    string line;
    while (getline(cin, line)) {
        array<long long, B + 1> dp = {};
        for (char c : line) {
            for (int i = B; i > 0; --i){
                dp[i] = max(dp[i], dp[i - 1] * 10 + c - '0');
            }
        }
        ans += dp[B];
    }
    cout << ans << "\n";
}