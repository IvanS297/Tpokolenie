#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll get_count(const map<int, vector<int>>& w, vector<int>& c, int n, int k, int ind) {
    if (n == ind) return 1;

    ll res = 0;
    for (int col = 0; col < k; ++col) {
        bool ok = true;
        if (w.count(ind)) {
            for (int nei : w.at(ind)) {
                if (c[nei] == col) {
                    ok = false;
                    break;
                }
            }
        }

        if (ok) {
            c[ind] = col;
            res += get_count(w, c, n, k, ind+1);
            c[ind] = -1;
        }
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m;
    cin >> n >> k >> m;

    map<int, vector<int>> wires;
    vector<int> cols(n, -1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        wires[u].push_back(v);
        wires[v].push_back(u);
    } 

    cout << get_count(wires, cols, n, k, 0) << '\n';
}