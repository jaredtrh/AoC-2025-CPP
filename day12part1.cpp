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

    vector<string> lines;
    string line;
    while (getline(cin, line)) {
        lines.push_back(move(line));
    }
    
    vector<int> areas;
    for (int i = 0; lines[i].back() == ':'; i += 5) {
        int area = 0;
        for (int j = i + 1; j <= i + 3; ++j) {
            area += count(lines[j].begin(), lines[j].end(), '#');
        }
        areas.push_back(area);
    }

    int ans = 0;
    for (int i = lines.size() - 1; !lines[i].empty(); --i) {
        auto s = split(lines[i], ": ");
        auto region = split(s[0], "x");
        auto qtys = split(s[1], " ");

        int sum = 0;
        for (int j = 0; j < qtys.size(); ++j) {
            sum += stoi(qtys[j]) * areas[j];
        }
        int available = stoi(region[0]) * stoi(region[1]);
        ans += sum <= available;
    }
    cout << ans << "\n";
}