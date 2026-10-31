#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        stack<char> st;
        string str;
        getline(cin, str);
        for (auto c : str) {
            bool push = false;
            while (!st.empty() && abs(st.top() - c) == 1) {
                if (c > st.top()) {
                    push = true;
                    break;
                }
                else st.pop();
            }
            if (!push) st.push(c);
        }
        while (!st.empty()) {
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }
}