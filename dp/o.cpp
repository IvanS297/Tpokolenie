#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const ll mod_ = 1e9+7;
    ll n;
    cin >> n;

    vector<ll> a(n+1);
    for (ll i = 1; i <= n; ++i) cin >> a[i];
    if (a[1] < 0 || a[n] > 25) {
        cout << 0 << '\n';
        return 0;
    }

    vector<ll> dp(26, 0);
    dp[a[1]] = 1;

    for (ll i = 2; i <= n; ++i) {
        vector<ll> next_dp(26, 0);
        for (ll v = 0; v <= 25; ++v) {
            ll _ways = 0;
            if (a[i] == 0) _ways = dp[v];
            else {
                if (v + a[i] <= 25) _ways = (_ways + dp[v+a[i]]) % mod_;
                if (v - a[i] >= 0) _ways = (_ways + dp[v-a[i]]) % mod_;
            }
            next_dp[v] = _ways;
        }
        dp = move(next_dp);
    }
    ll ways_ = 0;
    for (ll i = 0; i <= 25; ++i) {
        ways_ = (ways_ + dp[i]) % mod_;
    }

    cout << ways_ << '\n';
}
