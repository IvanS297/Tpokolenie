#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool check(vector<ll> vec, ll m, ll k) {
    if (m == 0) return true;

    ll n = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
        n += vec[i] / m;
    } 
    return n >= k;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, k;
    cin >> n >> k;
    vector<ll> x(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i];
    } 

    sort(x.begin(), x.end());
    ll l = 0;
    ll r = x[x.size()-1];
    ll ans = 0;
    while (l<=r) {
        ll m = l + (r-l)/2;
        if (check(x, m, k)) {
            ans = m;
            l = m+1;
        }
        else {
            r = m-1;
        }
    }
    cout << r << endl;
}

/*
что именно просят найти? - k максимально одинаковых и самых больших отрезков 
Какой модет быть диапозон значений - от 0 до максимальной длины самого большого отрезка
Если мне дадут орезок длиной x, то смогу ли я проверить, пожходит ли он?
Нужно проверить все n кусков и посмотреть, сколько раз помещается m в данном куске, и сложить этот результат в общий результат
*/