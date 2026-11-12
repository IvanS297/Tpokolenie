#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n+1, vector<int>(m+1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1));

    vector<char> cms;

    int i = 1, j = 1;

    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= m; ++j) {
            dp[i][j] = mat[i][j] + max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[n][m] << '\n';
    i--;
    j--;
    while (i > 1 || j > 1) {
        char to_push;
        if (i > 1 && j > 1) to_push = (dp[i-1][j] > dp[i][j-1]) ? 'D' : 'R';
        else {
            if (i > 1) to_push = 'D';
            else to_push = 'R';
        }

        if (to_push == 'D') i--;
        else j--;
    
        cms.push_back(to_push);
    }

    reverse(cms.begin(), cms.end());

    for (const auto& c : cms) {
        cout << c << ' ';
    }
    cout << '\n';
}