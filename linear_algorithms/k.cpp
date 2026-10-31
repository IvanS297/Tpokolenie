#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> a(n+2, vector<ll>(m+2)), p(n+2, vector<ll>(m+2));
    while (q--) {
        ll x1, y1, x2, y2, d;
        cin >> x1 >> y1 >> x2 >> y2 >> d;
        a[x1][y1] += d;
        a[x1][y2+1] -= d;
        a[x2+1][y1] -= d;
        a[x2+1][y2+1] += d;
    }

    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            p[i][j] = a[i][j] + p[i-1][j] + p[i][j-1] - p[i-1][j-1];
            cout << p[i][j] << " ";
        }
        cout << '\n';
    }
}