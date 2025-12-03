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

long long rangesum(long long l, long long r) {
    return (r * (r - 1) - l * (l - 1)) / 2;
}

long long calc(const string& x, bool incl) {
    long long res = 0;

    vector<long long> p(x.size() + 1);
    p[0] = 1;
    for (int i = 1; i <= x.size(); ++i) {
        p[i] = p[i - 1] * 10;
    }

    for (int k = 1; k * 2 < x.size(); ++k) {
        res += (p[k] + 1) * rangesum(p[k - 1], p[k]);
    }

    if (x.size() % 2 == 0) {
        long long pre = 0;
        for (int i = 0; i < x.size() / 2; ++i) {
            pre *= 10;
            res += (p[x.size() / 2] + 1) * rangesum((pre + (i == 0)) * p[x.size() / 2 - i - 1], (pre + x[i] - '0') * p[x.size() / 2 - i - 1]);
            pre += x[i] - '0';
        }
        bool ok = true;
        for (int i = x.size() / 2; i < x.size(); ++i) {
            if (x[i] != x[i - x.size() / 2]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            if (incl) {
                res += stoll(x);
            }
        } else {
            string s = x.substr(0, x.size() / 2);
            s += s;
            if (s < x) {
                res += stoll(s);
            }
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    string lines;
    string line;
    while (getline(cin, line)) {
        lines += line;
    }

    long long ans = 0;
    for (const string& range : split(lines, ",")) {
        auto s = split(range, "-");
        string l = s[0];
        string r = s[1];
        ans += calc(r, true) - calc(l, false);
    }
    cout << ans << "\n";
}