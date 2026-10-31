#include <bits/stdc++.h>
using namespace std;

#define MAX_ 100000

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    set<int> schematic;
    for (int i = 1; i < MAX_+n; ++i) {
        schematic.insert(i);
    }

    for (int i = 0; i < n; ++i) {
        int req;
        cin >> req;
        if (req > 0) { 
            if (schematic.find(req) == schematic.end()) {
                int can_get = *schematic.lower_bound(req);
                schematic.erase(can_get);
                cout << can_get << '\n';
            }
            else {
                schematic.erase(req);
                cout << req << '\n';
            }
        } else {
            schematic.insert(abs(req));
        }
    }
}