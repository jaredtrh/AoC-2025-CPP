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
    
    vector<pair<long long, long long>> ranges;

    string line;
    while (getline(cin, line)) {
        if (line.empty()) break;
        auto s = split(line, "-");
        ranges.emplace_back(stoll(s[0]), stoll(s[1]));
    }
    
    sort(ranges.begin(), ranges.end());

    long long right = 0;
    long long ans = 0;
    for (const auto& [l, r] : ranges) {
        ans += max(0ll, r - max(l - 1, right));
        right = max(right, r);
    }
    cout << ans << "\n";
}