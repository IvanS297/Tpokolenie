#include <bits/stdc++.h>
using namespace std;

#define ll long long

void print(stack<ll> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<ll> st;
    stack<ll> mins;
    int q;
    cin >> q;
    while (q--) {
        char o;
        cin >> o;
        switch (o)
        {
        case '1':
            ll x;
            cin >> x;
            st.push(x);
            if (!mins.empty()) mins.push(min(mins.top(), x));
            else mins.push(x);
            break;
        
        case '2':
            cout << st.top() << '\n';
            mins.pop();
            st.pop();
            break;

        case '3':
            cout << mins.top() << '\n';
            break;
        }
    }
}