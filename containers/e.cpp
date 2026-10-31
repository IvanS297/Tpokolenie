    #include <bits/stdc++.h>
    using namespace std;

    #define ll long long

    signed main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int q;
        cin >> q;

        deque<ll> deq, mins;

        while (q--) {
            char o;
            cin >> o;
            switch (o)
            {
            case '1':
                ll x;
                cin >> x;
                deq.push_back(x);
                if (mins.empty()) mins.push_back(x);
                else {
                    while (!mins.empty() && mins.back() > x) mins.pop_back();
                    mins.push_back(x);
                }
                break;
            case '2':
                cout << deq.front() << '\n';
                if (deq.front() == mins.front()) mins.pop_front();
                deq.pop_front(); 
                break;
            case '3':
                ll i;
                cin >> i;
                cout << deq[i-1] << '\n';
                break;
            case '4':
                cout << mins.front() << '\n';
                break;
            }
        }
    }