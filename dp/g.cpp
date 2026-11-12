#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<vector<ll>> dp(n+1, vector<ll>(10));
    for (ll i = 0; i <= 9; ++i) dp[1][i] = 1;
    dp[1][0] = 0;
    dp[1][8] = 0;

    for (ll i = 2; i <= n; ++i) {
        dp[i][0] = dp[i-1][6] + dp[i-1][4];
        dp[i][1] = dp[i-1][8] + dp[i-1][6];
        dp[i][2] = dp[i-1][9] + dp[i-1][7];
        dp[i][3] = dp[i-1][4] + dp[i-1][8];
        dp[i][4] = dp[i-1][0] + dp[i-1][3] + dp[i-1][9];
        dp[i][6] = dp[i-1][1] + dp[i-1][0] + dp[i-1][7];
        dp[i][7] = dp[i-1][2] + dp[i-1][6];
        dp[i][8] = dp[i-1][1] + dp[i-1][3];
        dp[i][9] = dp[i-1][2] + dp[i-1][4];
    }

    ll sum_ = 0;
    for (ll i = 0; i <= 9; ++i) sum_ += dp[n][i];
    cout << sum_ << '\n';
}