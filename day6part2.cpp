#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    
    vector<int> worksheet;
    long long ans = 0;

    string line;
    while (getline(cin, line)) {
        if (line[0] == '+' || line[0] == '*') {
            for (int i = 0; i < line.size(); ++i) {
                if (line[i] == ' ') continue;
                long long res = worksheet[i];
                for (int j = i + 1; j < line.size() && worksheet[j] > 0; ++j) {
                    if (line[i] == '*') {
                        res *= worksheet[j];
                    } else {
                        res += worksheet[j];
                    }
                }
                ans += res;
            }
            break;
        }
        
        if (worksheet.empty()) {
            worksheet.resize(line.size());
        }
        for (int i = 0; i < line.size(); ++i) {
            if (line[i] == ' ') continue;
            worksheet[i] = worksheet[i] * 10 + line[i] - '0';
        }
    }
    
    cout << ans << "\n";
}