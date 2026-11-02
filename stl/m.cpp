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

void print(const set<seg>& m, string s) {
    cout << s;
    for (const auto& s : m) cout << s.l << '\t';
    cout << '\n' << string(s.length(), ' ');
    for (const auto& s : m) cout << s.len << '\t';
    cout << '\n';
}

void print(const map<ll, seg>& mp_l, const map<ll, seg>& mp_r) {
    cout << "mp_l: ";

    for (const auto& p : mp_l) {
        size_t c = p.first;
        ll l = p.second.l;
        ll len = p.second.len;
        cout << c << "->";
        if (l == -1) cout << "[-1 -1]\t";
        else cout << '[' << l << ' ' << l + len-1 << "]\t";
    }
    cout << "\nmp_r: ";
    for (const auto& p : mp_r) {
        size_t c = p.first;
        ll l = p.second.l;
        ll len = p.second.len;
        cout << c << "->";
        if (l == -1) cout << "[-1 -1]\t";
        else cout << '[' << l << ' ' << l + len-1 << "]\t";
    }
    cout << '\n';   
}

void print(vector<bool>& success) {
    cout << "success: ";
    for (const auto& s : success) {
        cout << s << " ";
    }
    cout << '\n';
}

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
    vector<bool> suc(m+1, false);
    vector<seg> call_st(m+1);

    for (size_t i = 1; i <= m; ++i) {
        ll k;
        cin >> k;
        if (k > 0) {
            if (s.size() > 0) {
                auto it = prev(s.end());
                ll l = it->l;
                ll len = it->len;
                seg new_seg = {len-k, l+k};    
                if (k <= len) {
                erase({len, l}, s, mp_l, mp_r);
                if (k != len) {
                    s.insert(new_seg);
                    mp_l[l+k] = {len-k, l+k};
                    mp_r[l+len-1] = {len-k, l+k};
                }
                call_st[i] = {k, l};
                suc[i] = true;
                cout << call_st[i].l << '\n';
                } else cout << -1 << '\n';
            } else cout << -1 << '\n';
        }
        else {
            ll t = -k;
            if (!suc[t]) continue;
            seg to_del = call_st[t];
            ll l = to_del.l;
            ll len = to_del.len;
        
            ll new_l = l;
            ll new_len = len;
            
            auto l_it = mp_r.find(l-1);
            if (l_it != mp_r.end() && l_it->second.len > 0) {
                new_l = l_it->second.l;
                new_len += l_it->second.len;
                to_del = l_it->second;
                erase(to_del, s, mp_l, mp_r);
            }

            auto r_it = mp_l.find(l+len);
            if (r_it != mp_l.end() && r_it->second.len > 0) {
                new_len += r_it->second.len;
                to_del = r_it->second;
                erase(to_del, s, mp_l, mp_r);
            }

            s.insert({new_len, new_l});
            mp_l[new_l] = {new_len, new_l};
            mp_r[new_l+new_len-1] = {new_len, new_l}; 
        }
        // print(s, "memory: ");
        // print(mp_l, mp_r);
        // print(suc);
    }
}