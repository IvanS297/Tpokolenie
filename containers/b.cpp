#include  <bits/stdc++.h>
using namespace std;

int type(char c) {
    if (c == '(') return 0;
    if (c == ')') return 1;
    if (c == '[') return 2;
    if (c == ']') return 3;
    if (c == '{') return 4;
    return 5;
}

void solve(string& str) {
    stack<char> st;
    for (char c : str) {
        if (type(c) == 0 || type(c) == 2 || type(c) == 4) st.push(c);
        else {
            if (st.empty() || type(c)-1 != type(st.top())) {
                cout << "No" << '\n';
                return;
            }
            st.pop();
        }  
    }
    if (st.empty()) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);\
    solve(s);
}