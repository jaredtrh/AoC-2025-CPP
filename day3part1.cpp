#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    const int B = 2;

    long long ans = 0;
    string line;
    while (getline(cin, line)) {
        long long res = 0;
        int cnt = 0;
        for (int i = 0; i < line.size(); ++i) {
            while (res > 0 && line[i] - '0' > res % 10 && cnt - 1 + line.size() - i >= B) {
                res /= 10;
                cnt -= 1;
            }
            if (cnt < B) {
                res = res * 10 + line[i] - '0';
                cnt += 1;
            }
        }
        ans += res;
    }
    cout << ans << "\n";
}