#include <bits/stdc++.h>
using namespace std;

string get_max(const vector<string>& ps, vector<bool>& used, string cur, size_t c, size_t tot_c) {
    if (c == tot_c) return cur;

    int b_id = -1;
    for (int i = 0; i < ps.size(); ++i) {
        if (!used[i]) {
            if (b_id == -1) b_id = i;
            else if (ps[i] + ps[b_id] > ps[b_id] + ps[i]) b_id = i;
        }
    }
    used[b_id] = true;
    string res = get_max(ps, used, cur + ps[b_id], c+1, tot_c);
    used[b_id] = false;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string p;
    vector<string> ps;
    
    size_t n = 0;
    while (cin >> p) {
        ps.push_back(p);
        n++;
    }

    vector<bool> used(n, 0);

    cout << get_max(ps, used, "", 0, n) << '\n';
}