#include <bits/stdc++.h>
using namespace std;

struct delo {
    string name;
    string last_name;
    int class_num;
    char class_let;
    string db;
};

bool operator<(const delo a, const delo b) {
    if (a.class_num != b.class_num) return a.class_num < b.class_num;
    if (a.class_let != b.class_let) return a.class_let < b.class_let;
    if (a.last_name != b.last_name) return a.last_name < b.last_name;
    return a.name < b.name;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    set<delo> dels;
    while (n--) {
        string del = "";
        string last_name, name, clas, db;
        cin >> last_name >> name >> clas >> db;
        delo a = {name, last_name, stoi(clas.substr(0, clas.length()-1)), clas[clas.length()-1], db};
        dels.insert(a);
    }

    for (auto i : dels) {
        cout << i.class_num << i.class_let << ' ' << i.last_name << ' ' << i.name << ' ' << i.db << '\n';
    }
}