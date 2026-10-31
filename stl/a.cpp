#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    unordered_map<string, string> m1, m2;
    while (n--) {
        string w1, w2;
        cin >> w1 >> w2;
        m1[w1] = w2;
        m2[w2] = w1;
    }
    string q;
    cin >> q;
    if (m1.find(q) != m1.end()) cout << m1[q] << '\n';
    else cout << m2[q] << '\n';
}