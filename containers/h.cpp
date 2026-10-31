#include <bits/stdc++.h>
using namespace std;

pair<int, int> get_uhod(int h, int m) {
    m += 20;
    h += (m / 60) % 16000000;
    m %= 60;
    cout << h << " " << m << '\n';
    return {h, m};
}

pair<int, int> get_hm(int t) {
    int h = t / 60;
    int m = t - 60 * h;
    return {h, m};
}

inline int gt(int h, int m) {
    return h*60+m;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    deque<int> q;
    int cur_time = 0;
    while (n--) {
        int h, m, s;
        cin >> h >> m >> s;
        cur_time = gt(h, m); 
        if (!q.empty()) {
            while (!q.empty() && q.front() <= cur_time) {
                q.pop_front();
            }
            int uhod = q.empty() ? cur_time + 20 : q.back() + 20;
            if (s >= q.size()) {
                q.push_back(uhod);
                pair<int, int> u = get_hm(uhod);
                cout << u.first << " " << u.second << '\n';
            }
            else cout << h << " " << m << '\n';
        }
        else {
            q.push_back(gt(h, m)+20);
            pair<int, int> u = get_hm(q.back());
            cout << u.first << " " << u.second << '\n';
        }
    }
}