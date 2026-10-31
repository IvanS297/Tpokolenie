#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool is_prime(ll n) {
    for (ll d = 2; d*d <= n; ++d) {
        if (n%d == 0) return false;
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    if (is_prime(n)) cout << "prime\n";
    else cout << "composite\n";
}