#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll p;

ll bin_pow(ll x, ll n) {
    if (n == 0) return 1;
    if (n % 2 == 1) {
        return (x * bin_pow(x, n-1)) % p;
    }
    ll b = bin_pow(x, n/2);
    return b*b%p;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x, n;
    cin >> x >> n >> p;
    cout << bin_pow(x, n) << '\n';
}