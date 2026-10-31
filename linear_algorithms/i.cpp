#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a;
    while (n--) {
        ll ai;
        cin >> ai;
        a.push_back(ai);
    }

    ll l = 0, r = a.size()-1;
    ll s1 = a[l], s2 = a[r];
    ll min_diff = abs(s1-s2), ans_l = l, ans_r = r;
    while (l + 1 < r) {
        if (s1 <= s2) {
            l++;
            s1 += a[l];
        }
        else {
            r--;
            s2 += a[r];
        }

        if (abs(s1-s2) < min_diff) {
            min_diff = abs(s1-s2);
            ans_r = r;
            ans_l = l;
        }
    }
    cout << min_diff << " " << ans_l+1 << " " << ans_r+1 << '\n';
}