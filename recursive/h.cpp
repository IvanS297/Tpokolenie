#include <bits/stdc++.h>
using namespace std;

void merge_sort(vector<pair<int, int>>& to_sort) {
    if (to_sort.size() <= 1) return;
    int m = to_sort.size() / 2;
    vector<pair<int, int>> left(to_sort.begin(), to_sort.begin()+m);
    vector<pair<int, int>> right(to_sort.begin()+m, to_sort.end());
    merge_sort(left);
    merge_sort(right);

    int i = 0, j = 0, k = 0;
    while (i < (int)left.size() && j < (int)right.size()) {
        if (left[i].first != right[j].first) {
            if (left[i].first < right[j].first) to_sort[k++] = left[i++];
            else if (left[i].first > right[j].first) to_sort[k++] = right[j++];
        }
        else if (left[i].second != right[j].second) {
            if (left[i].second < right[j].second) to_sort[k++] = left[i++];
            else if (left[i].second > right[j].second) to_sort[k++] = right[j++];
        }
        else {
            to_sort[k++] = left[i++];
            to_sort[k++] = right[j++];
        }
    }
    while (i < (int)left.size()) to_sort[k++] = left[i++];
    while (j < (int)right.size()) to_sort[k++] = right[j++]; 
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> guys(n);
    for (int i = 0; i < n ;++i) {
        cin >> guys[i].first >> guys[i].second;
    }

    merge_sort(guys);

    for (auto g : guys) {
        cout << g.first << ' ' << g.second << '\n';
    }
}