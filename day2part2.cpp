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

long long calc(string x, bool incl) {
    long long res = 0;
    
    vector<int> mobius(x.size() + 1, 1);
    for (int d = 2; d <= x.size(); ++d) {
        if (mobius[d] == 0) continue;
        for (int i = d; i * d <= x.size(); ++i) {
            if (i % d == 0) {
                mobius[i * d] = 0;
            } else {
                mobius[i * d] *= -1;
            }
        }
    }

    vector<long long> p(x.size() + 1);
    p[0] = 1;
    for (int i = 1; i <= x.size(); ++i) {
        p[i] = p[i - 1] * 10;
    }

    vector<long long> ones(x.size(), 1);
    for (int d = 2; d <= x.size(); ++d) {
        for (int i = 1; i * d <= x.size(); ++i) {
            ones[i] = ones[i] * p[i] + 1;
            if (i * d < x.size()) {
                res += ones[i] * rangesum(p[i - 1], p[i]) * mobius[d];
            }
        }
    }

    vector<int> pi(x.size());
    for (int i = 0; i < x.size(); ++i) {
        int xi = x[i] - '0';
        for (int dig = i == 0; dig < xi; ++dig) {
            x[i] = '0' + dig;

            if (i > 0) {
                pi[i] = pi[i - 1];
                while (pi[i] > 0 && x[i] != x[pi[i]]) {
                    pi[i] = pi[pi[i] - 1];
                }
                if (x[i] == x[pi[i]]) {
                    pi[i] += 1;
                }
            }

            int len = i + 1 - pi[i];
            long long pre = 0;
            for (int k = 1; k < x.size(); ++k) {
                if (k - 1 <= i) {
                    pre = pre * 10 + x[k - 1] - '0';
                }

                if (x.size() % k == 0) {
                    int d = x.size() / k;
                    if (k > i) {
                        res += ones[k] * rangesum(pre * p[k - i - 1], (pre + 1) * p[k - i - 1]) * mobius[d];
                    } else if (k % len == 0) {
                        res += ones[k] * pre * mobius[d];
                    }
                }
            }
        }
        x[i] = '0' + xi;

        if (i > 0) {
            pi[i] = pi[i - 1];
            while (pi[i] > 0 && x[i] != x[pi[i]]) {
                pi[i] = pi[pi[i] - 1];
            }
            if (x[i] == x[pi[i]]) {
                pi[i] += 1;
            }
        }
    }
    if (incl && pi.back() > 0 && x.size() % (x.size() - pi.back()) == 0) {
        res += stoll(x);
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