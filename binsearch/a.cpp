#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;
    vector<ll> a;
    while (n--) {
        ll ai;
        cin >> ai;
        a.push_back(ai);
    }

    sort(a.begin(), a.end());
    
    while (q--) {
        ll x;
        cin >> x;
        ll l = 0;
        ll r = a.size();
        while (r-l > 1) {
            ll m = (r+l)/2;
            if (a[m] >= x) r=m;
            else l=m;
        }
        if (a[r] == x) cout << "YES\n";
        else cout << "NO\n";
    }
}