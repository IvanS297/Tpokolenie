#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll binsearch(const vector<ll>& vec, ll target) {
    ll l = 0;
    ll r = vec.size()-1;
    ll res = 0;
    while (l <= r) {
        ll m = l + (r-l)/2;
        if (vec[m] >= target) {
            res = m;
            r = m-1;
        }
        else {
            l = m +1;
        }
    }
    return res;
}

bool check(const vector<ll>& pref, const vector<ll>& suff, ll m, ll n, ll k) {
    ll x = binsearch(pref, m);
    ll y = n - 1 - binsearch(suff, m);
    if (x >= y) return true;
    return (y-x <= k);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<ll> a(n);
        ll sum = 0;
        for (size_t i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        ll l = 1;
        ll r = sum;
        ll ans = sum;
        vector<ll> pref(n), suff(n);
        pref[0] = a[0];
        for (size_t i = 1; i < n; ++i) pref[i] = pref[i-1]+a[i];
        suff[0] = a[n-1];
        for (size_t i = 1; i < n; ++i) suff[i] = suff[i-1]+a[n-1-i];
        while (l <= r) {
            ll m = l + (r-l)/2;
            if (check(pref, suff, m, n, k)) {
                ans = m;
                r = m-1;
            }       
            else {
                l = m+1;
            }
        }
        cout << ans << endl;
    }
}