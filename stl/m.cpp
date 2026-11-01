#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct seg {
    ll len, l;
    bool operator<(const seg& s1) const {
        if (len != s1.len) return len < s1.len;
        return l < s1.l;
    }
};

void erase(const seg& s1, set<seg>& s, map<ll, seg>& mp_l, map<ll, seg>& mp_r) {
    s.erase(s1);
    mp_l[s1.l] = {-1, -1};
    mp_r[s1.len+s1.l-1] = {-1, -1};
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    set<seg> s;
    s.insert({n, 1});

    map<ll, seg> mp_l, mp_r;
    vector<seg> st_call;

    while (m--) {
        ll k;
        cin >> k;
        if (k > 0) {
            cout << '\n';
            // auto it = s.lower_bound({k, 0});
            auto it = prev(s.end());
            if (it != s.end()) {
                ll id = it->l;
                ll len = it->len; 
                s.erase(it);
                mp_l[id] = {-1, -1};
                mp_r[len-1] = {-1, -1};
                if (k < len) {
                    s.insert({len-k, id+k});
                    mp_l[id+k-1] = {len-k+1, id+k};
                    mp_r[id+len-1] = {len-k+1, id+k};
                    // st_call.push_back({len-k, id+k});
                    // cout << "new free space from " << st_call.back().l << " to: " << st_call.back().l + st_call.back().len-1 << '\n';
                }
            }
        }
        // else {
        //     if (st_call.size() > -1*k) {
        //         auto it = st_call[-1*k-1];
        //         ll len = it.len;
        //         ll id = it.l;

        //         if (mp_l[len+id-1].l > 0) {
        //             len = mp_l[len+id-1].l-id+1;
        //         }

        //         if (mp_l[len+id-1].len > 0) {
        //             ll len_r = mp_l[len+id-1].len;
        //             erase(mp_l[len+id-1], s, mp_l, mp_r);
        //             len += len_r;
        //         }

        //         if (mp_r[id-1].len > 0) {
        //             ll len_l = mp_r[id-1].len;
        //             erase(mp_r[id-1], s, mp_l, mp_r);
        //             len+=len_l;
        //             id = len_l;
        //         }

        //         s.insert({len, id});
        //         cout << "free from " << id << " to: " << id + len-1 << '\n';
        //         mp_l[id] = {len, id};
        //         mp_r[len+id-1] = {len, id};
        //     }
        // }
        cout << "mp_l: ";
        for (auto i : mp_l) cout << i.first << '\t';
        cout << "\nmp_r: ";
        for (auto i : mp_r) cout << i.first << '\t';
        cout << '\n';   
    }
}