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
    for (int i = 2; i <= n+1; ++i) {
        for (int j = 2; j <= m+1; ++j) {
            dp[i+1][j+2] += dp[i][j];
            // dp[i-1][j-2] += dp[i][j];
        
            dp[i+2][j+1] += dp[i][j];
            // dp[i+2][j-1] += dp[i][j];
        
        }
    }
    cout << dp[n+1][m+1] << '\n';
}