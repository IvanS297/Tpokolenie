#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<vector<ll>> dp(3, vector<ll>(n+1));
    
    dp[0][1] = 1;
    dp[1][1] = 1;
    dp[2][1] = 0;
    
    for (ll i = 2; i <= n; ++i) {
        dp[0][i] = dp[0][i-1] + dp[1][i-1] + dp[2][i-1];
        dp[1][i] = dp[0][i-1];
        dp[2][i] = dp[1][i-1];
    }

    cout << dp[0].back()+dp[1].back()+dp[2].back() << '\n';
}