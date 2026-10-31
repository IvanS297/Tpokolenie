#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), p(n+1), cnt(m+1, 0);
    vector<vector<ll>> o;
    
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < m; ++i) {
        ll ri, li, di;
        cin >> li >> ri >> di;
        o.push_back({li-1, ri-1, di});
    }
    for (ll i = 0; i < k; ++i) {
        ll xi, yi;
        cin >> xi >> yi;
        cnt[xi-1]++;
        cnt[yi]--;
    }
    ll ops_cnt = 0;
    for (ll i = 0; i < m; ++i) {
        ops_cnt += cnt[i];
        p[o[i][0]] += ops_cnt * o[i][2];
        p[o[i][1]+1] -= ops_cnt * o[i][2];
    }
    ll add = 0;
    for (ll i = 0; i < n; ++i) {
        add += p[i];
        cout << a[i] + add << " ";
    }
    cout << endl;
}