#include <bits/stdc++.h>
using namespace std;

inline const int get_t(int f) {
    return max(1000-f, 1);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n+1);
    set<pair<int, int>> s;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s.insert({get_t(a[i]), i});
    }

    int pos = 1;
    int cur_t = 0;

    while (true) {
        int next_t = (*s.begin()).first;
        int id = (*s.begin()).second;
        s.erase(s.begin());

        if (abs(id - pos) <= next_t-cur_t) {
            pos = id;
            cur_t = next_t;
            a[id]++;
            s.insert({cur_t + get_t(a[id]), id});
        }
        else {
            cout << next_t << '\n';
            break;
        }
    }
}