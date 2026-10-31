#include <bits/stdc++.h>
using namespace std;

void print(string& s, int n, int k) {
    if (n == 0 && k == 0) {
        cout << s << '\n';
        return;
    }
    if (n == 0) return;
    if (n > k) {
        s.push_back('0');
        print(s, n-1, k);
        s.pop_back();
    } 
    if (k != 0) {
        s.push_back('1');
        print(s, n-1, k-1);
        s.pop_back();
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    string s;

    print(s, n, k);
}