#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool check(vector<ll>& vec, ll k, ll dist) {
    ll count = 1;
    ll last_p = vec[0];
    for (ll i =1; i < vec.size(); ++i) {
        if (vec[i]-last_p >= dist) {
            count++;
            last_p = vec[i];
        }
    }
    return count>=k;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    vector<ll> s(n);
    for (ll i =0; i < n; ++i) {
        cin >> s[i];
    }

    sort(s.begin(), s.end());
    ll l = 0;
    ll r = s[n-1]-s[0];
    ll ans = 0;
    while (l<=r) {
        ll m = l + (r-l)/2;
        if (check(s, k, m)) {
            ans = m;
            l = m+1;
        }
        else {
            r = m-1;
        }
    }
    cout << ans << endl;
}