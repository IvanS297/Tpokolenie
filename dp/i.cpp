#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    // dp[i][j] - использовали i кубиков, размер последней - j
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));

    for (ll i = 1; i <= n; ++i) dp[i][i] = 1;

    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            if (dp[i][j] > 0) {
                for (ll k = j + 1; i + k <= n; ++k) dp[i + k][k] += dp[i][j];
            }
        }
    }

    ll sum_ = 0;
    for (ll j = 1; j <= n; ++j) sum_ += dp[n][j];

    cout << sum_ << '\n';
}