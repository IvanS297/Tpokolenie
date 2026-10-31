#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    double c;
    cin >> c;
    double l = 0;
    double r = sqrt(c)+1;
    for (int i = 0; i < 100; ++i) {
        double m = (l+r) * 0.5;
        if (m*m + sqrt(m) - c > 0) {
            r = m;
        }
        else {
            l = m;
        }
    }
    cout << fixed << setprecision(6) << l << endl;
}