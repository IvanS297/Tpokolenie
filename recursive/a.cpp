#include <bits/stdc++.h>
using namespace std;

void print(string& s, int n) {
    if (n== 0) {
        cout << s << '\n';
        return;
    }
    s.push_back('0');
    print(s, n-1);
    s.back() = '1';
    print(s, n-1);
    s.pop_back();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    print(s, n);
}