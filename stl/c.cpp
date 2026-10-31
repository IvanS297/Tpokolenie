#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    set<int> a, b;
    cin >> n;
    while (n--) {
        int temp;
        cin >> temp;
        a.insert(temp);
    }
    cin >> k;
    while (k--) {
        int temp;
        cin >> temp;
        b.insert(temp);
    }

    int count = 0;
    set<int> c;
    
    auto ait = a.begin();
    auto bit = b.begin();

    while (ait != a.end() && bit != b.end()) {
        if (*ait == *bit) {
            ait++;
            bit++;
        }
        else {
            count++;
            if (*ait < *bit) {
                c.insert(*ait);
                ait++;
            }
            else {
                c.insert(*bit);
                bit++;
            }
        }
    }

    while (ait != a.end()) {
        count++;
        c.insert(*ait);
        ait++;
    }

    while (bit != b.end()) {
        count++;
        c.insert(*bit);
        bit++;
    }

    cout << count << '\n';
    for (auto i : c) {
        cout << i << " ";
    }
    cout << '\n';
}