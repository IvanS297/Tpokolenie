#include <bits/stdc++.h>
using namespace std;

void print(stack<pair<int, int>> st) {
    while (!st.empty()) {
        cout << "{" << st.top().first << " " << st.top().second << "}" << " ";
        st.pop();
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    stack<pair<int, int>> st;

    int n;
    cin >> n;
    int m = 0;

    while (n--) {
        int c;
        cin >> c;
        while (!st.empty() && st.top().first != c && st.top().second >= 3) {
            m += st.top().second;
            st.pop();
        }

        if (!st.empty() && c == st.top().first) {
            st.top().second++;
        } 
        else st.push({c, 1});
    }
    if (!st.empty() && st.top().second >= 3) {
        m += st.top().second;
        st.pop();
    }
    
    cout << m << '\n';
}