#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b;
    cin >> a >> b;

    ll cnt = 0;

    while (a != b) {
        if (b > a) b -= a;
        else a -= b;
        cnt++;
    }
    cout << cnt+1 << '\n';
}