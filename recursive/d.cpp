#include <bits/stdc++.h>
using namespace std;

void print(vector<bool>& used, vector<int>& p, int n, int k) {
    if (k == 0) {
        for (auto i : p) cout << i;
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n ; ++i) {
        if (used[i]) continue;
        used[i] = true;
        p.push_back(i);
        print(used, p, n, k-1);
        p.pop_back();
        used[i] = false;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<bool> used(n);
    vector<int> p;
    print(used, p, n, n);
}