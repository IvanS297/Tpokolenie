#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    stack<ll> st;
    ll time = 0, t;
    while (n--) {
        int c;
        cin >> c;
        if (c == 0) {
            int x;
            cin >> x;
            st.push(0);
        }
        else {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int t = max(a, b) + 1;
            st.push(t);
        }
    }
    cout << st.top() << '\n';
}