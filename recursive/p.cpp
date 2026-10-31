#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll merge(vector<ll>& s1, vector<ll>& s2, vector<ll>& a) {
    size_t i = 0;
    size_t j = 0;
    ll inv = 0;
    while (i < s1.size() && j < s2.size()) {
        if (s1[i] > s2[j]) {
            a[i+j] = s2[j];
            j++;
            inv += s1.size() - i;
        }
        else {
            a[i+j] = s1[i];
            i++;
        }
    }

    while (i < s1.size()) {
        a[i+j] = s1[i];
        i++;
    }

    while (j < s2.size()) {
        a[i+j] = s2[j];
        j++;
    }
    return inv;
}

ll sort(vector<ll>& a) {
    if (a.size() <= 1) return 0;
    ll m = a.size()/2;
    ll inv = 0;
    vector<ll> s1(a.begin(), a.begin()+m);
    vector<ll> s2(a.begin()+m, a.end());
    inv += sort(s1);
    inv += sort(s2);
    inv += merge(s1, s2, a);
    return inv;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, l;
    cin >> n >> l;
    vector<ll> T(n);
    for (ll i = 0; i < n; ++i) {
        ll w;
        cin >> w;
        T[i] = i + l * w;
    }
    
    cout << sort(T) << "\n";

}