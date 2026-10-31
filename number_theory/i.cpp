#include <bits/stdc++.h>
using namespace std;

#define ll long long

void swap(ll& a, ll& b) {
    ll temp = a;
    a = b;
    b = temp;
}

ll gcd(ll a, ll b) {
    if (a >= b) swap(a, b);
    if (a == 0) return b;
    return gcd(a, b%a);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    cout << gcd(n-1, m-1)+1 << '\n';
}