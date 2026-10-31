#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll get_sum(deque<pair<ll, ll>>& deq, ll c) {
    ll sum = 0;
    while (!deq.empty() && c > 0) {
        if (c >= deq.front().second) {
            ll t = deq.front().second;
            sum += t * deq.front().first;
            deq.pop_front();
            c -= t;
        }
        else {
            sum += c * deq.front().first;
            deq.front().second -= c;
            c -= c;
        }
    }
    return sum;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<pair<ll, ll>> deq;
    ll Q;
    cin >> Q;
    while (Q--) {
        char o;
        cin >> o;
        switch (o)
        {
        case '1':
            ll x, c;
            cin >> x >> c;
            deq.push_back({x, c});
            break;
        
        case '2':
            ll C;
            cin >> C;
            ll sum = get_sum(deq, C);
            cout << sum << '\n';
            break;
        }
    }
}