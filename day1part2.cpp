#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    string line;
    int dial = 50;
    int ans = 0;
    while (getline(cin, line)) {
        char dir = line[0];
        int dist = stoi(line.substr(1));
        ans += dist / 100;
        if (dir == 'R') {
            ans += dist % 100 >= 100 - dial;
            dial = (dial + dist) % 100;
        } else {
            ans += dial > 0 && dist % 100 >= dial;
            dial = (dial - dist % 100 + 100) % 100;
        }
    }
    cout << ans << "\n";
}