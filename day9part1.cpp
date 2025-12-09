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

    vector<pair<int, int>> red;

    string line;
    while (getline(cin, line)) {
        auto s = split(line, ",");
        red.emplace_back(stoi(s[0]), stoi(s[1]));
    }
    int n = red.size();
    
    long long ans = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            ans = max(ans, (long long)(abs(red[i].first - red[j].first) + 1) * (abs(red[i].second - red[j].second) + 1));
        }
    }
    cout << ans << "\n";
}