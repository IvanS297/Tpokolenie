#include <bits/stdc++.h>
using namespace std;

void decomp(int n, int last_slog, vector<int>& slogs) {
    if (n == 0) {
        for (auto x: slogs) cout << x << ' ';
        cout << '\n';
        return;
    }
    for (int i = n; i >= last_slog; --i) {
        slogs.push_back(i);
        decomp(n-i, i, slogs);
        slogs.pop_back();
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> slogs;
    decomp(n, 1, slogs);
}