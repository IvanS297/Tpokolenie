#include <bits/stdc++.h>
using namespace std;

void print1(vector<int>& a, int n, int k) {
    if (n == 0) {
        for (auto i : a) cout << i;
        cout << '\n';
        return;
    }
    for (int i = 0; i < k; ++i) {
        a.push_back(i);
        print1(a, n-1, k);
        a.pop_back();
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a;
    print1(a, n, k);
}