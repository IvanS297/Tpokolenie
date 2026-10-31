#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct student {
    string name, last_name;
    ll d, m, y;
    int score;
    int k;
    vector<string> ks;
};

struct university {
    string name;
    int k = 0;
    vector<student> students;
};

bool operator<(const student& s1, const student& s2) {
    if (s1.score != s2.score) return s2.score < s1.score;
    if (s1.y != s2.y) return s1.y < s2.y;
    if (s1.m != s2.m) return s1.m < s2.m;
    if (s1.d != s2.d) return s1.d < s2.d;
    if (s1.last_name != s2.last_name) return s1.last_name < s2.last_name;
    return s1.name < s2.name;
}

bool cmp(const student& s1, const student& s2) {
    if (s1.last_name != s2.last_name) return s1.last_name < s2.last_name;
    if (s1.name != s2.name) return s1.name < s2.name;
    if (s1.d != s2.d) return s1.d < s2.d;
    if (s1.m != s2.m) return s1.m < s2.m;
    return s1.y < s2.y;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    map<string, university> uns;
    while (n--) {
        university un;
        cin >> un.name;
        cin >> un.k;
        uns[un.name] = un;
    }

    ll m;
    cin >> m;
    multiset<student> s;
    for (ll i = 0; i < m; ++i) {
        student si;
        cin >> si.name >> si.last_name >> si.d >> si.m >> si.y >> si.score >> si.k;
        for (ll j = 0; j < si.k; ++j) {
            string title;
            cin >> title;
            si.ks.push_back(title);
        }
        s.insert(si);
    }

    for (const auto& si : s) {
        for (const auto& un : si.ks) {
            if (uns.find(un) != uns.end() && uns[un].k > 0) {
                uns[un].k--;
                uns[un].students.push_back(si);
                break;
            }
        }
    }

    for (auto& un : uns) {
        cout << un.first << " ";
        sort(un.second.students.begin(), un.second.students.end(), cmp);
        for (const auto& st : un.second.students) {
            cout << '\t' << st.name << ' ' << st.last_name << '\t';
        }
        cout << '\n';
    }
}