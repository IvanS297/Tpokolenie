#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("dictionary.in");
    ofstream fout("dictionary.out");

    string input;
    map<string, set<string>> la;
    while (getline(fin, input)) {
        string w1, w2;
        char t;
        stringstream ss(input);
        ss >> w1;
        ss >> t;
        while (ss >> w2) {
            if (w2[w2.size()-1] == ',') w2 = w2.substr(0, w2.size()-1);
            la[w2].insert(w1);
        }
    }
    fout << la.size() << '\n';
    for (auto i : la) {
        fout << i.first << " - ";
        for (set<string>::iterator j = i.second.begin(); j != i.second.end(); ++j) {
            fout << *j;
            if (next(j) != i.second.end()) fout << ',';
            fout << ' ';
        }
        fout << '\n';
    }
}