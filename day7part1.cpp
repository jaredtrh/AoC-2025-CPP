#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    
    vector<bool> beam;
    int ans = 0;

    string line;
    while (getline(cin, line)) {
        if (beam.empty()) {
            beam.resize(line.size());
            beam[line.find('S')] = true;
        }

        for (int i = 1; i < line.size() - 1; ++i) {
            if (line[i] == '^' && beam[i]) {
                ans += 1;
                beam[i] = false;
                beam[i - 1] = true;
                beam[i + 1] = true;
            }
        }
    }
    
    cout << ans << "\n";
}