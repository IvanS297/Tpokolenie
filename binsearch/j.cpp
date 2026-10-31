#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll h(const vector<ll>& vec, ll w) {
    ll lines = 1;
    ll w1 = 0;
    
    for (ll l : vec) {
        if (l > w) return 1e18;
        if (w1 == 0) w1 = l;
        else if (w1 + 1 + l <= w) w1 += (1+l);
        else {
            lines++;
            w1 = l;
        }
    }
    return lines;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll w, n, m;
    cin >> w >> n >> m;
    vector<ll> a(n), b(m);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll j = 0; j < m; ++j) {
        cin >> b[j];
    }
    
    ll l = *max_element(a.begin(), a.end());
    ll r = w - *max_element(b.begin(), b.end());
    ll min_h = 1e18;

    while (l <= r) {
        ll w1 = l + (r-l)/2;
        ll w2 = w - w1;

        ll h1 = h(a, w1);
        ll h2 = h(b, w2);
        ll needed = max(h1, h2);
        min_h = min(min_h, needed);
        if (h1 > h2) {
            l = w1 + 1;
        } else {
            r = w1 - 1;
        }
    }
    cout << min_h << endl;
}