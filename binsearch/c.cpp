#include <bits/stdc++.h>
using namespace std;

#define ll long long

inline bool f(ll m, ll x, ll y, ll n) {
    return (m/x) + (m/y) >= n-1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x, y;
    cin >> n >> x >> y;
    ll l = 0;
    ll r = min(x, y)*(n-1);
    while (r-l > 1) {
        ll m = (l+r)/2;
        if (f(m, x, y, n)) r = m;
        else l = m;
    }
    cout << r+min(x, y) << "\n";
}