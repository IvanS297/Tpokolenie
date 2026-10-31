#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll d, R;
    cin >> d >> R;
    vector<ll> a;
    while (d--) {
        ll ai;
        cin >> ai;
        a.push_back(ai);
    }
    
    ll c = 0;
    ll r = 0;
    for (ll l = 0; l < a.size(); l++) {
        while (r < a.size() && a[r] - a[l] <= R) {
            r++;
        }
        c += a.size() - r;
    }
    cout << c << endl;
}