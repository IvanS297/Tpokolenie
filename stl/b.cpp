#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;

    vector<int> a;
    int back = k-1;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    multiset<int> win;
    for (int i = 0; i < k; ++i) {
        win.insert(a[i]);
    }
    cout << *win.begin() << ' ';
    for (int i = k; i < n; ++i) {
        win.insert(a[i]);
        win.extract(a[i-k]);
        cout << *win.begin() << ' ';
    }
    cout << '\n';
}