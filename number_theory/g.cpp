#include <bits/stdc++.h>
using namespace std;

#define ll long long

void swap(ll& a, ll& b) {
    ll temp = a;
    a = b;
    b = temp;
}

ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(a, b%a);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<pair<int, int>> coords(n);
    while (n--) {
        cin >> coords[coords.size()-n-1].first >> coords[coords.size()-n-1].second;
    }

    ll cnt = 0;

    for (size_t i = 1; i < coords.size(); ++i) {
        ll prev_x = coords[i-1].first;
        ll prev_y = coords[i-1].second;
        ll x = coords[i].first;
        ll y = coords[i].second;
        cnt += gcd(abs(x - prev_x), abs(y - prev_y));
    }
    cnt += gcd(abs(coords[0].first - coords[coords.size()-1].first), abs(coords[0].second - coords[coords.size()-1].second));
    cout << cnt << '\n';
}
