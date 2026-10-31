#include <bits/stdc++.h>
using namespace std;

void decomp(int n, int last_slog, vector<int>& slogs) {
    if (n == 0) {
        for (auto i : slogs) cout << i << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= min(last_slog, n); ++i) {
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
    decomp(n, n, slogs);
    cout << '\n';
}