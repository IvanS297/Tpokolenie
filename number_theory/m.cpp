#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int128 __int128

void factorization(int128 x, vector<pair<ll, ll>>& res) {
    for (int128 d = 2; d*d <= x; ++d) {
        if (x % d == 0) {
            ll cnt = 0;
            while (x % d == 0) {
                cnt++;
                x /= d;
            }
            res.push_back({d, cnt});
        }
    }
    if (x > 1) res.push_back({x, 1});
}

void get_dels(int128 x, vector<ll>& dels) {
    for (int128 d = 1; d*d <= x; ++d) {
        if (x % d == 0) {
            dels.push_back(d);
            if (d*d != x) {
                dels.push_back(x/d);
            }
        }
    }
}

int128 bin_pow(int128 x, int128 n) {
    if (n == 0) return 1;
    if (n % 2 == 1) return x*bin_pow(x, n-1);
    int128 b = bin_pow(x, n/2);
    return (b*b);
} 

int128 find_nok(vector<ll>& posl, int128 limit) {
    int128 NOK = 1;
    map<ll, ll> nok;
    for (auto& i : posl) {
        
        if (i == 1) continue;

        vector<pair<ll, ll>> fact;

        factorization(i, fact);
        for (const auto& [p, a] : fact) {
            nok[p] = max(nok[p], a);
        }
    }   
    for (const auto& [p, a] : nok) {
        NOK *= bin_pow(p, a);
        if (NOK > limit) return limit+1;
    }
    return NOK;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> posl(n);
        set<ll> posl_copy;

        for (ll i = 0; i < n; ++i) {
            cin >> posl[i];
            posl_copy.insert(posl[i]);
        }

        int128 max_el = *max_element(posl.begin(), posl.end());
        
        int128 NOK = find_nok(posl, max_el);
        if (NOK > max_el || posl_copy.count(NOK) == 0) {
            cout << n << '\n';
            continue;
        }

        vector<ll> dels;
        get_dels(NOK, dels);
        ll max_len = 0;
        for (auto& x : dels) {
            if (posl_copy.count(x) > 0) continue;
            vector<ll> sub_posl;
            for (int128 num : posl) {
                if (x % num == 0) sub_posl.push_back(num);
            }
            if (!sub_posl.empty() && find_nok(sub_posl, max_el) == x) {
                max_len = max(max_len, static_cast<ll>(sub_posl.size()));
            }
        }

        cout << max_len << '\n';
    }
}