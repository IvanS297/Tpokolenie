#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x;
    cin >> x;
    set<ll> dels;
    for (ll d = 1; d*d <= x; ++d) {
        if (x%d==0) {
            dels.insert(d);
            dels.insert(x/d);
        }
    }

    cout << dels.size() << '\n';
    for (auto& i : dels) {
        cout << i << ' ';
    }
    cout << '\n';
}