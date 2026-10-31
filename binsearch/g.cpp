#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double l = -2000;
    double r = 2000;
    if (a < 0) {
        a *= -1;
        b *= -1;
        c *= -1;
        d *= -1;
    }
    for (int i = 0; i < 100; ++i) {
        double m = (l+r)/2;
        if (a*m*m*m+b*m*m+c*m+d > 0) {
            r = m;
        }
        else {
            l = m;
        }
    }
    cout << fixed << setprecision(20) << (l+r)/2 << endl;
}