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

    map<string, vector<string>> adj;

    string line;
    while (getline(cin, line)) {
        auto s = split(line, ": ");
        adj[s[0]] = split(s[1], " ");
    }

    map<string, long long> dp = {{"fft", 1}};
    auto dfs = [&](const auto& self, const string& s) -> long long {
        if (dp.count(s)) return dp[s];
        long long res = 0;
        for (const auto& nxt : adj[s]) {
            res += self(self, nxt);
        }
        return dp[s] = res;
    };

    long long ans = dfs(dfs, "svr");
    dp = {{"dac", 1}};
    ans *= dfs(dfs, "fft");
    dp = {{"out", 1}};
    ans *= dfs(dfs, "dac");
    cout << ans << "\n";
}