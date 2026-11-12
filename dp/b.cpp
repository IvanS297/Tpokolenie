#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> dp(n+1), a(n+1);

    for (int i = 1; i <= n; ++i) cin >> a[i];

    dp[1] = a[1];
    if (n > 1) dp[2] = a[2];

    for (int i = 3; i <= n; ++i) {
        dp[i] = min(dp[i-1],dp[i-2])+a[i];
    }

    cout << dp.back() << '\n';
}