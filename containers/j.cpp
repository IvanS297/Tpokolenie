#include <bits/stdc++.h>
using namespace std;

#define ll long long

queue<ll> way1, way2;
stack<ll> tp;
vector<pair<ll, ll>> coms;

void add_com(ll com) {
    if (!coms.empty() && coms.back().first == com) {
        coms.back().second++;
    }
    else coms.push_back({com, 1});
}

void move(ll w) {
    if (!way2.empty() && way2.back() > w) {
        cout << "0\n";
        exit(0);
    }
    way2.push(w);
    add_com(2);
}

void print1(queue<ll> deq, string str) {
    cout << str;
    while (!deq.empty()) {
        cout << deq.front() << " ";
        deq.pop();
    }
    cout << endl;
}

void print1(stack<ll> deq, string str) {
    cout << str;
    while (!deq.empty()) {
        cout << deq.top() << " ";
        deq.pop();
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    while (n--) {
        ll num;
        cin >> num;
        way1.push(num);
    }

    n = way1.size();
    ll wanted = 1;
    while (wanted <= n) {
        if (!way1.empty() && wanted == way1.front()) {
            tp.push(way1.front());
            way1.pop();
            add_com(1);
            way2.push(tp.top());
            tp.pop();
            add_com(2);
        }
        else if (!tp.empty() && wanted == tp.top()) {
            way2.push(tp.top());
            tp.pop();
            add_com(2);
        }
        else {
            while (!way1.empty() && way1.front() != wanted) {
                tp.push(way1.front());
                way1.pop();
                add_com(1);
            }
            if (way1.empty()) {
                cout << "0\n";
                exit(0);
            }
            else {
                tp.push(way1.front());
                way1.pop();
                add_com(1);
                way2.push(tp.top());
                tp.pop();
                add_com(2);
            }
        }
        wanted++;
    }
    // print1(way1, "way1 ");
    // print1(way2, "way2 ");
    // print1(tp, "tp ");
    cout << coms.size() << '\n';
    for (auto c : coms) {
        cout << c.first << " " << c.second << '\n';
    }
}