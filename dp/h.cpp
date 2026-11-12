#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e9;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> dp(n+1, INF);
    vector<ll> prev(n+1, -1);
    dp[1] = 0;

    for (ll i = 1; i <= n; ++i) {
        if (i < n && dp[i]+1 < dp[i+1]) {
            dp[i+1] = dp[i]+1;
            prev[i+1] = i;
        }
        if (i <= n/2 && dp[i]+1 < dp[2*i]) {
            dp[2*i] = dp[i]+1;
            prev[2*i] = i;
        }
        if (i <= n/3 && dp[i]+1 < dp[3*i]) {
            dp[3*i] = dp[i]+1;
            prev[3*i] = i;
        }
    }

    vector<ll> ops;
    for (ll v = n; v != -1; v = prev[v]) {
        ll p = prev[v];
        if (v == p+1) ops.push_back(1);
        else if (v == 2*p) ops.push_back(2);
        else if (v == 3*p) ops.push_back(3);
    }

    for (vector<ll>::reverse_iterator it = ops.rbegin(); it != ops.rend(); ++it) cout << *(it);
    cout << '\n';
}