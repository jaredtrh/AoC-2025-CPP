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

    auto iscorner = [&](int i) -> bool {
        const auto& [x, y] = red[i];
        const auto& [px, py] = red[(i - 1 + n) % n];
        const auto& [nx, ny] = red[(i + 1) % n];

        long long ax = x - px;
        long long ay = y - py;
        long long bx = nx - x;
        long long by = ny - y;
        return ax * by > ay * bx;
    };
    auto checkhor = [&](int lx1, int lx2, int ly) -> bool {
        for (int i = 0; i < n; ++i) {
            const auto& [x, y] = red[i];
            const auto& [nx, ny] = red[(i + 1) % n];
            if (x == nx) {
                const auto& [mny, mxy] = minmax(y, ny);
                if (lx1 < x && x < lx2 && mny < ly && ly < mxy) return false;
            } else {
                if (y == ly) {
                    if (iscorner(i) && (x < nx ? lx1 < x && x <= lx2 : lx1 <= x && x < lx2)) return false;
                    if (iscorner((i + 1) % n) && (nx < x ? lx1 < nx && nx <= lx2 : lx1 <= nx && nx < lx2)) return false;
                }
            }
        }
        return true;
    };
    auto checkver = [&](int lx, int ly1, int ly2) -> bool {
        for (int i = 0; i < n; ++i) {
            const auto& [x, y] = red[i];
            const auto& [nx, ny] = red[(i + 1) % n];
            if (y == ny) {
                const auto& [mnx, mxx] = minmax(x, nx);
                if (ly1 < y && y < ly2 && mnx < lx && lx < mxx) return false;
            } else {
                if (x == lx) {
                    if (iscorner(i) && (y < ny ? ly1 < y && y <= ly2 : ly1 <= y && y < ly2)) return false;
                    if (iscorner((i + 1) % n) && (ny < y ? ly1 < ny && ny <= ly2 : ly1 <= ny && ny < ly2)) return false;
                }
            }
        }
        return true;
    };
    
    long long ans = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            long long area = (long long)(abs(red[i].first - red[j].first) + 1) * (abs(red[i].second - red[j].second) + 1);
            if (area > ans) {
                const auto& [xi, yi] = red[i];
                const auto& [xj, yj] = red[j];
                const auto& [mnx, mxx] = minmax(xi, xj);
                const auto& [mny, mxy] = minmax(yi, yj);
                if (checkhor(mnx, mxx, mny) && checkhor(mnx, mxx, mxy) && checkver(mnx, mny, mxy) && checkver(mxx, mny, mxy)) {
                    ans = area;
                }
            }
        }
    }
    cout << ans << "\n";
}