#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k, q;
    cin >> n >> m >> k;
    vector<vector<vector<ll>>> a(n, vector<vector<ll>>(m, vector<ll>(k)));
    vector<vector<vector<ll>>> p(n+1, vector<vector<ll>>(m+1, vector<ll>(k+1)));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            for (ll z = 0; z < k; ++z) {
                cin >> a[i][j][z];
                p[i+1][j+1][z+1] = a[i][j][z] + p[i][j+1][z+1] + p[i+1][j][z+1] + p[i+1][j+1][z] 
                - p[i][j][z+1] - p[i][j+1][z] - p[i+1][j][z]
                + p[i][j][z];
            }
        }
    }
    cin >> q;
    for (ll i = 0; i < q; ++i) {
        ll lx, ly, lz, rx, ry, rz;
        cin >> lx >> ly >> lz >> rx >> ry >> rz;
        lx--; ly--; lz--;

        ll sum = p[rx][ry][rz] - p[lx][ry][rz] - p[rx][ly][rz] - p[rx][ry][lz]
               + p[lx][ly][rz] + p[lx][ry][lz] + p[rx][ly][lz] 
               - p[lx][ly][lz];
        cout << sum << " ";
    }
    cout << endl;
}