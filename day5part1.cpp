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
    
    bool flag = false;
    vector<pair<long long, long long>> ranges;
    vector<long long> ids;

    string line;
    while (getline(cin, line)) {
        if (flag) {
            ids.push_back(stoll(line));
        } else {
            if (line.empty()) {
                flag = true;
                continue;
            }
            auto s = split(line, "-");
            ranges.emplace_back(stoll(s[0]), stoll(s[1]));
        }
    }
    
    sort(ranges.begin(), ranges.end());
    sort(ids.begin(), ids.end());

    long long right = 0;
    int i = 0;
    int ans = 0;
    for (const auto& [l, r] : ranges) {
        if (r > right) {
            while (i < ids.size() && ids[i] <= r) {
                ans += ids[i] >= l;
                i += 1;
            }
            right = r;
        }
    }
    cout << ans << "\n";
}