#include <bits/stdc++.h>
using namespace std;

#define ll long long

void factorization(ll n, vector<pair<ll, ll>>& out) {
    for (ll d = 2; d * d <= n; ++d) {
        if (n%d == 0) {
            ll cnt = 0;
            while (n % d == 0) {
                cnt++;
                n /= d;
            }
            out.push_back({d, cnt});
        }
    }
    if (n > 1) {
        out.push_back({n, 1});
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<pair<ll, ll>> simple_nums;
    factorization(n, simple_nums);

    for (size_t i =0; i < simple_nums.size(); ++i) {
        cout << simple_nums[i].first;
        if (simple_nums[i].second != 1) {
            cout << '^' << simple_nums[i].second;
        }
        if (i + 1 < simple_nums.size()) {
            cout << '*';
        }
    }
    cout << '\n';
}
