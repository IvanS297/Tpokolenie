#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    vector<int> a(n + 1);
    vector<queue<int>> color_indices(k + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        color_indices[a[i]].push(i);
    }

    vector<int> counts(k + 1, 0);
    vector<bool> consumed(n + 1, false);
    int distinct_colors = 0;
    vector<vector<int>> answers;

    for (int r = 1; r <= n; ++r) {
        int current_color = a[r];
        if (counts[current_color] == 0) {
            distinct_colors++;
        }
        counts[current_color]++;

        int expired_idx = r - m - 1;
        if (expired_idx >= 1) {
            if (!consumed[expired_idx]) {
                int expired_color = a[expired_idx];
                counts[expired_color]--;
                if (counts[expired_color] == 0) {
                    distinct_colors--;
                }
            }
        }

        if (distinct_colors == k) {
            vector<int> current_set;
            int left_bound = r - m;
            for (int c = 1; c <= k; ++c) {
                while (!color_indices[c].empty() && color_indices[c].front() < left_bound) {
                    color_indices[c].pop();
                }

                int idx = color_indices[c].front();
                color_indices[c].pop();

                current_set.push_back(idx);
                consumed[idx] = true;
                counts[c]--;
                if (counts[c] == 0) {
                    distinct_colors--;
                }
            }
            answers.push_back(current_set);
        }
    }

    cout << answers.size() << "\n";
    for (const auto& set : answers) {
        for (int i = 0; i < k; ++i) {
            cout << set[i] << (i == k - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
