#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool check(ll w, ll h, ll n, ll m) {
    ll strs = m / h;
    ll cols = m / w;
    if (strs >= n || cols >= n) return true;
    return (strs*cols) >= n;
} 

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll w, h, n;
    cin >> w >> h >> n;

    ll l = max(w, h);
    ll r = max(w, h)*n;
    ll ans = 0;

    while (l <= r) {
        ll m = l + (r-l)/2;
        if (check(w, h, n, m)) {
            ans = m;
            r = m-1;
        }
        else {
            l = m+1;
        }
    }
    cout << ans << endl;
}