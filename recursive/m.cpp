#include <bits/stdc++.h>
using namespace std;

bool decomp(const vector<int>& money, vector<int>& used, int ost, size_t idx) {
    if (ost == 0) {
        cout << "Yes\n" << used.size() << '\n';
        for (const auto& i : used) cout << i << ' ';
        cout << '\n';
        return true;
    }

    for (size_t i = idx; i < money.size(); ++i) {
        if (money[idx] <= ost) {
            used.push_back(money[i]);
            if (decomp(money, used, ost-money[i], i+1)) return true;
            used.pop_back();
        }
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;                                                                                                                                                                                                                                                                                                                                                                       
    cin >> n >> k;

    vector<int> money;
    vector<int> used;

    while (n--) {
        int temp;
        cin >> temp;
        money.push_back(temp);
        money.push_back(temp);
    }

    sort(money.rbegin(), money.rend());
    if (!decomp(money, used, k, 0)) cout << "No\n";
}