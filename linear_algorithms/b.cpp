#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;

    vector<ll> a(n, 0), p(n, 0);
    while (q--) {
        ll l, r, d;
        cin >> l >> r >> d;
        a[l-1] += d;
        a[r] -= d;
    }
    
    cout << endl;
    p[0] = a[0];
    for (ll i = 0; i < n; i++) {
        p[i+1] = p[i] + a[i+1];
        cout << p[i] << " ";
    }
    cout << '\n';
}