#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, q;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    vector<vector<ll>> p(n, vector<ll>(m));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (i > 0 && j > 0) p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + a[i][j];
            else {
                if (i == 0 && j == 0) {
                    p[i][j] = a[i][j];
                } else if (i == 0) {
                    p[i][j] = p[0][j-1] + a[0][j];
                } else {
                    p[i][j] = p[i-1][0] + a[i][0];
                }
            }
        }
    }

    cin >> q;
    while (q--) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1-=2;
        y1-=2;
        x2--;
        y2--;
        if (x1 < 0 && y1 < 0) cout << p[x2][y2] << " ";
        else if (x1 < 0) cout << p[x2][y2] - p[x2][y1] << " "; 
        else if (y1 < 0) cout << p[x2][y2] - p[x1][y2] << " ";
        else {
            ll sum = p[x2][y2] - p[x2][y1] - p[x1][y2] + p[x1][y1];
            cout << sum << " ";
        }
    }
    cout << '\n';
}