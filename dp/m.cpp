#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const int inf_ = 1e9;

    vector<int> a(n+1), cost(n+1, inf_); // cost[i] - стоимость разбить последовательность длиной i на группы
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a.begin()+1, a.end());
    cost[0] = 0;

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (cost[j-1] != inf_) {
                int grup_cost = a[i]-a[j];
                cost[i] = min(cost[i], cost[j-1] + grup_cost);
            }
        }
    }

    cout << cost[n] << '\n'; 
}