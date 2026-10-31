#include <bits/stdc++.h>
using namespace std;

bool is_safe(vector<vector<int>>& br, vector<int>& lad, int r, int c) {
    if (br[r][c] == 1) return false;
    for (int i = 0; i < r; ++i) {
        if (lad[i] == c) return false;
    }
    return true;
}

int get_count(vector<vector<int>>& br, vector<int>& lad, int n, int r) {
    if (r == n) return 1;

    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (is_safe(br, lad, r, i)) {
            lad[r] = i;
            res += get_count(br, lad, n, r+1);
            lad[r] = -1;
        }
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> br(n, vector<int>(n, -1));
    vector<int> lad(n, -1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char status;
            cin >> status;
            if (status == 'X') br[i][j] = 1;
        }
    }

    cout << get_count(br, lad, n, 0) << '\n';
}