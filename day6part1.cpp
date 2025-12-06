#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    
    vector<vector<int>> worksheet;
    long long ans = 0;

    string line;
    while (getline(cin, line)) {
        if (line[0] == '+' || line[0] == '*') {
            int j = 0;
            for (char c : line) {
                if (c == ' ') continue;
                long long res = c == '*';
                for (int i = 0; i < worksheet.size(); ++i) {
                    if (c == '*') {
                        res *= worksheet[i][j];
                    } else {
                        res += worksheet[i][j];
                    }
                }
                ans += res;
                j += 1;
            }
            break;
        }
        
        istringstream iss(line);
        copy(istream_iterator<int>(iss), istream_iterator<int>(), back_inserter(worksheet.emplace_back()));
    }
    
    cout << ans << "\n";
}