#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp.back() << '\n';
}