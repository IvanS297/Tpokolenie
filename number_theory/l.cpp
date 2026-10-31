#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int128 __int128

ll a;

int128 bin_pow(int128 x, int128 n) {
    if (n == 0) return 1;
    if (n % 2 == 1) return x*bin_pow(x, n-1)%static_cast<int128>(a);
    int128 b = bin_pow(x, n/2);
    return (b*b)%a;
} 

int128 factorization(int128 x) {
    int128 t = 1;
    for (int128 d = 2; d*d <= x; ++d) {
        if (x % d == 0) {
            while (x % d == 0) {
                x /= d;
            }
            t *= d;
        }
    }
    if (x > 1) t *= x;
    return t;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a;
    if (a == 1) {
        cout << 1 << '\n';
        return 0;
    }
    vector<pair<int128, int128>> res;
    ll n0 = factorization(a);
    ll n = n0;
    while (true) {
        if (bin_pow(n, n) == 0) {
            cout << n << '\n';
            return 0;
        }
        n += n0;
    }
}