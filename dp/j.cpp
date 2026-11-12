#include <bits/stdc++.h>
using namespace std;

using  ll = long long;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int INF = 1e9;

    int n;
    cin >> n;
    vector<int> c(n+1), dp(n+1, 0);
    for (int i = 1; i <= n; ++i) cin >> c[i];
    sort(c.begin()+1, c.end());
    if (n == 2) {
        cout << c[2] - c[1] << '\n';
        return 0;
    }
    dp[1] = INF;
    dp[2] = c[2]-c[1];
    if (n >= 3) {
        dp[3] = c[3] - c[1];
    }
    for (int i = 4; i <= n; ++i) {
        dp[i] = min(dp[i-1]+(c[i]-c[i-1]), dp[i-2] + (c[i]-c[i-1]));
    }
    cout << dp[n] << '\n';
}