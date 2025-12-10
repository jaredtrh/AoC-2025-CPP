#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string& s, const string& delim) {
    vector<string> res;
    int pos = 0;
    while (true) {
        int nxt = s.find(delim, pos);
        if (nxt == string::npos) {
            res.push_back(s.substr(pos));
            break;
        }
        res.push_back(s.substr(pos, nxt - pos));
        pos = nxt + delim.size();
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    int ans = 0;

    string line;
    while (getline(cin, line)) {
        auto s = split(line, " ");
        int lights = 0;
        for (int i = 1; i < s[0].size() - 1; ++i) {
            if (s[0][i] == '#') {
                lights |= 1 << (i - 1);
            }
        }
        vector<int> buttons;
        for (int i = 1; i < s.size() - 1; ++i) {
            int mask = 0;
            for (const string& x : split(s[i].substr(1, s[i].size() - 2), ",")) {
                mask |= 1 << stoi(x);
            }
            buttons.push_back(mask);
        }

        queue<int> q; q.push(0);
        vector<bool> vis(1 << (s[0].size() - 2));
        bool done = false;
        while (!q.empty()) {
            for (int rep = q.size(); rep > 0; --rep) {
                int mask = q.front(); q.pop();
                if (vis[mask]) continue;
                if (mask == lights) {
                    done = true;
                    break;
                }
                vis[mask] = true;

                for (int button : buttons) {
                    q.push(mask ^ button);
                }
            }
            if (done) break;
            ans += 1;
        }
    }

    cout << ans << "\n";
}