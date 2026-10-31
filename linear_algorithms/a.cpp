#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n;

    vector<ll> a, p; 
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        a.push_back(ai);
    }

    p.push_back(0);
    for (ll i = 1; i <= n; ++i) {
        p.push_back(p[i-1] + a[i-1]);
    }

    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        cout << p[r] - p[l-1] << ' ';
    }
    cout << '\n';
}