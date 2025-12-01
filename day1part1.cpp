#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("day1part1.txt", "r", stdin);

    string line;
    int dial = 50;
    int ans = 0;
    while (getline(cin, line)) {
        char dir = line[0];
        int dist = stoi(line.substr(1));
        if (dir == 'R') {
            dial = (dial + dist) % 100;
        } else {
            dial = (dial - dist % 100 + 100) % 100;
        }
        ans += dial == 0;
    }
    cout << ans << "\n";
}