#include <bits/stdc++.h>
using namespace std;

#define ll long long

void get_p(ll n, vector<pair<ll, ll>>& res) {
    for (ll d = 2; d*d <= n; ++d) {
        if (n % d == 0) {
            ll cnt = 0;
            while (n % d == 0) {
                cnt++;
                n /= d;
            }
            res.push_back({d, cnt});
        }
    }
    if (n > 1) res.push_back({n, 1});
} 

ll power_in_fact(ll p, ll n) {
    ll cnt = 0;
    ll del = p;
    while (n / del > 0) {
        cnt += n / del;
        if (n/p < del) break;
        del *= p;
    }
    return cnt;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> dels;
    get_p(k, dels);
    ll zeros = -1;

    for (const auto& [p, a] : dels) {
        ll loc_zeros = power_in_fact(p, n)/a;
        if (zeros == -1 || loc_zeros < zeros) zeros = loc_zeros;
    }
    cout << zeros << '\n';
}