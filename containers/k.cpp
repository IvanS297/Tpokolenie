#include <bits/stdc++.h>
using namespace std;

void balance_deq(deque<int>& d1, deque<int>& d2) {
    if (d1.size() < d2.size()) {
        d1.push_back(d2.front());
        d2.pop_front();
    } else if (d1.size() > d2.size() + 1) {
        d2.push_front(d1.back());
        d1.pop_back();
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    deque<int> q1, q2;
    while (n--) {
        char c;
        cin >> c;
        int i;
        switch (c)
        {
        case '+':
            cin >> i;
            q2.push_back(i);
            balance_deq(q1, q2);
            break;
        
        case '-':
            cout << q1.front() << '\n';
            q1.pop_front();
            balance_deq(q1, q2);
            break;
        
        case '*':;
            cin >> i;
            q2.push_front(i);
            balance_deq(q1, q2);
            break;
        }
    }
}