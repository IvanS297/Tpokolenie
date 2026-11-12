#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n+1, vector<int>(m+1));

    vector<vector<int>> dp(n+5, vector<int>(m+5));
    dp[2][2] = 1;

    int s = 4; 
    while (s < n + m + 2) {
        int i1 = 2;
        while (i1 <= n + 1) {
            int j1 = s - i1; 
            if (j1 >= 2 && j1 <= m + 1) {
                if (dp[i1][j1] > 0) {
                    dp[i1 + 1][j1 + 2] += dp[i1][j1];
                    dp[i1 - 1][j1 + 2] += dp[i1][j1];
                    dp[i1 + 2][j1 + 1] += dp[i1][j1];
                    dp[i1 + 2][j1 - 1] += dp[i1][j1];
                }
            }
            i1++;
        }
        s++; 
    }
    cout << dp[n+1][m+1] << '\n';
}