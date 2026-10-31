#include <bits/stdc++.h>
using namespace std;

#define ll long long

void merge(vector<ll>& parent, vector<ll>& s1, vector<ll>& s2) {
    size_t n = s1.size();
    size_t m = s2.size();

    size_t i = 0, j = 0;
    while (i < n && j < m) {
        if (s1[i] < s2[j]) {
            parent[i+j] = s1[i];
            i++;
        }
        else {
            parent[i+j] = s2[j];
            j++;
        }
    }
    while (i < n) {
        parent[i+j] = s1[i];
        i++;
    }
    while (j < m) {
        parent[i+j] = s2[j];
        j++;
    }
}

void sort(vector<ll>& a, int n) {
    if (n <= 1) return;
    int m = n/2;
    vector<ll> s1(a.begin(), a.begin()+m);
    vector<ll> s2(a.begin()+m, a.end());
    sort(s1, s1.size());
    sort(s2, s2.size());
    merge(a, s1, s2);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> to_sort(n);
    for (ll i = 0; i < n; ++i) {
        cin >> to_sort[i];
    }
    sort(to_sort, to_sort.size());
    for (auto i : to_sort) {
        cout << i << ' ';
    }
    cout << '\n';
}