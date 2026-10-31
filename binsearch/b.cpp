#include <bits/stdc++.h>
using namespace std;

#define ll long long

pair<ll, ll> bin_search(vector<ll>& vec, ll k) {
    ll l = 0;
    ll r = vec.size();
    while (r-l>1) {
        ll m = (l+r)/2;
        if (vec[m] > k) {
            r = m;
        }
        else l = m;
    }
    return {l, r};
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    vector<ll> a, b;
    while (n--) {
        ll ai;
        cin >> ai;
        a.push_back(ai);
    }   
    while (k--) {
        ll ki;
        cin >> ki;
        pair<ll, ll> res = bin_search(a, ki);
        if (abs(a[res.first] - ki) < abs(a[res.second] - ki)) cout << a[res.first] << "\n";
        else if (abs(a[res.first] - ki) > abs(a[res.second] - ki)) cout << a[res.second] << "\n";
        else cout << a[min(res.first, res.second)] << "\n";
    }
}