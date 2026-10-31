#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
    if (n == 0 || n == 1) return false;
    for (int d = 2; d*d <= n;++d) {
        if (n % d == 0) return false;
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int a, b;
    for (int pi = 2; pi < n; ++pi) {
        if (is_prime(pi) && is_prime(n-pi)) {
            cout << pi << ' ' << n-pi << '\n';
            break;
        }
    }
}