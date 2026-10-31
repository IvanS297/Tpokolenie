#include <bits/stdc++.h>
using namespace std;

#define ll long long


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> vec(n);
    map<ll, ll> cnt;

    for (ll i = 0; i < n; ++i) {
        cin >> vec[i];
        cnt[vec[i]]++;
    }

    for (const auto& [k, v] : cnt) {
        for (ll i = 0; i < v; ++i) {
            cout << k << ' ';
        }
    }

    cout << '\n';
}