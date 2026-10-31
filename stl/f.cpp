#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n, k, c = 0;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll ans = 0, left = 0, right = n-1;
        while (left < right) {
            ll sum = a[left] + a[right];
            if (sum < k) left++;
            else if (sum > k) right--;
            else {
                if (a[left] == a[right]) {
                    ll c = right - left + 1;
                    ans += c * (c - 1) / 2;
                    break;  
                }
                ll left_val = a[left];
                ll left_c = 0;
                while (left < right && a[left] == left_val) {
                    left_c++;
                    left++;
                }
                ll right_val = a[right];
                ll right_c = 0;
                while (right >= left && a[right] == right_val) {
                    right_c++;
                    right--;
                }
                ans += left_c * right_c;
            }
        }
        cout << ans << '\n';
    }
}