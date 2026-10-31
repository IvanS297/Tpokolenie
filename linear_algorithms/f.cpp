#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x;
    cin >> x;
    vector<ll> a, b, c;
    for (ll i = 1; i <= x; ++i) {
        a.push_back(i * i);
    }
    ll osn = 1;
    while (osn * osn * osn < x * x) {
        b.push_back(osn*osn*osn);
        osn++;
    }

    ll a_ptr = 0, b_ptr = 0;
    while (a_ptr < a.size() && b_ptr < b.size()) {
        if (a[a_ptr] > b[b_ptr]) {
            c.push_back(b[b_ptr]);
            b_ptr++;
        }
        else if (a[a_ptr] < b[b_ptr]) {
            c.push_back(a[a_ptr]);
            a_ptr++;
        }
        else {
            c.push_back(a[a_ptr]);
            a_ptr++;
            b_ptr++;
        }
    }
    while (a_ptr < a.size()) {
        c.push_back(a[a_ptr]);
        a_ptr++;
    }
    while (b_ptr < b.size()) {
        c.push_back(b[b_ptr]);
        b_ptr++;
    }
    cout << c[x-1] << endl;
}