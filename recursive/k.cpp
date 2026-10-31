#include <bits/stdc++.h>
using namespace std;

bool is_safe(vector<int>& p, int r, int c) {
    for (int i = 0; i < r; ++i) {
        if (p[i] == c) return false;
        if (abs(p[i] - c) == abs(r-i)) return false;
    }
    return true;
}

int get_count(vector<int>& p, int n, int r) {
    if (r == n) return 1;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (is_safe(p, r, i)) {
            p[r] = i;
            res += get_count(p, n, r+1);
            p[r] = -1;
        }
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n, -1);
    cout << get_count(p, n, 0) << '\n';
}