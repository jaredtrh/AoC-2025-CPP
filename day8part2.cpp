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

    vector<array<int, 3>> boxes;

    string line;
    while (getline(cin, line)) {
        auto s = split(line, ",");
        boxes.push_back({stoi(s[0]), stoi(s[1]), stoi(s[2])});
    }
    int n = boxes.size();
    
    vector<tuple<long long, int, int>> conns;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            long long x = boxes[i][0] - boxes[j][0];
            long long y = boxes[i][1] - boxes[j][1];
            long long z = boxes[i][2] - boxes[j][2];
            conns.push_back({x * x + y * y + z * z, i, j});
        }
    }
    sort(conns.begin(), conns.end());

    vector<int> dsu(n, -1);
    auto dsufind = [&](const auto& self, int i) -> int {
        return dsu[i] < 0 ? i : self(self, dsu[i]);
    };
    auto dsuunion = [&](int i, int j) -> void {
        i = dsufind(dsufind, i);
        j = dsufind(dsufind, j);
        if (i == j) return;
        if (dsu[i] > dsu[j]) {
            swap(i, j);
        }
        dsu[i] += dsu[j];
        dsu[j] = i;
    };

    for (const auto& [_, i, j] : conns) {
        dsuunion(i, j);
        if (-dsu[dsufind(dsufind, 0)] == n) {
            cout << (long long)boxes[i][0] * boxes[j][0] << "\n";
            break;
        }
    }
}