#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll by_mod(ll x, ll mod) {
    return (x%mod + mod) % mod;
}

const ll mod_ = 1e9+7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll k, n;
    cin >> k >> n;

    vector<ll> dp(n+2);
    dp[1] = 1;
    ll base_sum = 1;
    for (ll i = 2; i <= n+1; ++i) {
        dp[i] = base_sum;
        base_sum = by_mod(base_sum+dp[i], mod_);
        if (i>=k) base_sum = by_mod(base_sum - dp[i-k], mod_);
    }
    cout << dp.back() << '\n';
}
