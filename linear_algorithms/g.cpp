#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& vec) {
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> n1, n2, n3, n4;
    for (int n = 1; n <= 4; ++n) {
        int i;
        cin >> i;
        while (i--) {
            int ai;
            cin>> ai;
            switch (n)
            {
                case 1: n1.push_back(ai); break;
                case 2: n2.push_back(ai); break;
                case 3: n3.push_back(ai); break;
                case 4: n4.push_back(ai); break;
            }
        }
    }
    sort(n1.begin(), n1.end());
    sort(n2.begin(), n2.end());
    sort(n3.begin(), n3.end());
    sort(n4.begin(), n4.end());

    int i = 0, j = 0, k = 0, m = 0;
    int ansi = 0, ansj = 0, ansk = 0, ansm = 0;
    unsigned int min_diff = -1;
    while (i < n1.size() && j < n2.size() && k < n3.size() && m < n4.size()) {
        vector<int> temp = {n1[i], n2[j], n3[k], n4[m]};
        int ma = *max_element(temp.begin(), temp.end());
        int mi = *min_element(temp.begin(), temp.end());
        int diff = ma - mi;
        if (diff < min_diff) {
            min_diff = diff;
            ansi = i;
            ansj = j;
            ansm = m;
            ansk = k;
        }
        if (mi == temp[0]) i++;
        else if (mi == temp[1]) j++;
        else if (mi == temp[2]) k++;
        else if (mi == temp[3]) m++;
        
    }
    cout << n1[ansi] << " " << n2[ansj] << " " << n3[ansk] << " " << n4[ansm] << endl;
}