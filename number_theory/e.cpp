#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b;
    cin >> a >> b;
    
    vector<bool> p(b+1, true);
    p[0] = 0;
    p[1] = 0;
    for (ll i = 2; i <= b; ++i) {
        if (p[i] == 0) continue;
        else {
            for (ll d = i*i; d <= b; d+=i) {
                p[d] = 0;
            }
        }
    }
    for (ll i = a; i <= b; ++i) {
        if (p[i]) cout << i << ' ';
    }
    cout << '\n';
}