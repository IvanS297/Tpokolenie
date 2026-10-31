#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define INF 1e9

const vector<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
ll minm = INF+1;

void find_minm(ll n_left, int p_idx, ll last_a, ll cur_m) {
    if (n_left == 1) {
        minm = min(minm, cur_m);
        return;
    }
    if (p_idx >= (int)primes.size()) return;

    ll p = primes[p_idx];
    ll p_pow = 1;

    for (ll alpha = 1; alpha <= last_a; ++alpha) {
        if (INF / p < p_pow) break; 
        p_pow *= p;
        if (INF / p_pow < cur_m) break;
        if (n_left % (alpha + 1) == 0) find_minm(n_left / (alpha + 1), p_idx + 1, alpha, cur_m * p_pow);
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    if ( n== 1) {
        cout << 1 << '\n';
        return 0;
    }
    find_minm(n, 0, n - 1, 1);
    if (minm > INF) cout << 0 << '\n';
    else cout << minm << '\n';
}