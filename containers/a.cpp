#include <bits/stdc++.h>
using namespace std;

void solve(string& str) {
    stack<char>st;
    for (char c : str) {
        if (c == '(') {
            st.push('(');
        }
        else {
            if (st.empty()) {
                cout << "No" << '\n';
                return;
            }
            else st.pop();
        }
    }
    if (st.empty()) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);
    solve(s);
}