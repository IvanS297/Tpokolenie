#include <bits/stdc++.h>
using namespace std;

#define ll long long

inline bool check(ll a, ll b, ll d, ll w, ll h, ll n) {
    return ((w/(a+2*d))*(h/(b+2*d)) >= n || (w/(b+2*d))*(h/(a+2*d)) >= n);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, a, b, w, h;
    cin >> n >> a >> b >> w >> h;
    ll l = 0;
    ll r = max(w, h);
    ll d = 0;

    while (l <= r) {
        ll m = l + (r-l)/2;
        if (check(a, b, m, w, h, n)) {
            d = m;
            l = m+1;
        }
        else {
            r = m-1;
        }
    }
    cout << d << endl;
}