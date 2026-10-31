#include <bits/stdc++.h>
using namespace std;

void print(stack<int> st) {
    cout << "st ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop(); 
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    stack<int> st;
    while (n--) {
        char o;
        cin >> o;
        if (o == '0') {
            int a;
            cin >> a;
            st.push(a);
        }
        else if (o == '1') {
            int a, b;
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            st.push(a+b);
        }
        else if (o == '2') {
            int a, b;
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            st.push(a-b);
        }
        else if (o == '3') {
            int a, b;
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            st.push(a*b);
        }
    }
    cout << st.top() << '\n';
}