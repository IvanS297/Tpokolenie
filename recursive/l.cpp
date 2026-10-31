#include <bits/stdc++.h>
using namespace std;

string get_p(const map<char, int>& sl, map<char, int>::const_iterator it, string cen) {
    if (it == sl.end()) return cen;
    
    string temp = string((*it).second/2, (*it).first);
    return temp + get_p(sl, next(it), cen) + temp;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;

    map<char, int> slovar;
    for (size_t i = 0; i < s.size(); ++i){ 
        slovar[s[i]]++;
    } 
    string cen;
    for (const auto& [k, c] : slovar) {
        if (c % 2 == 1) {
            cen = string(1, k);
            break;
        }
    }
    string p = "";
    p = get_p(slovar, slovar.begin(), cen);
    cout << p << '\n';
}