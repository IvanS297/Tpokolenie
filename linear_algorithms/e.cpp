#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll p = 0, ans = a[0], min_p = 0;
    int r_ans = 0, l_ans = 0, idx = 0;
    for (int r = 1; r <= n; ++r) {
        p += a[r-1];
        ll sum = p - min_p;
        if (sum > ans) {
            l_ans = idx;
            r_ans = r;
            ans = sum;
        }
        if (p < min_p) {
            idx = p;
            min_p = p;
        }
    }
    cout << ans << '\n';
}