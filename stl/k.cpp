#include <bits/stdc++.h>
using namespace std;

char get_code(char c) {
    if (c >= 'a' && c <= 'c') return '2';
    if (c >= 'd' && c <= 'f') return '3';
    if (c >= 'g' && c <= 'i') return '4';
    if (c >= 'j' && c <= 'l') return '5';
    if (c >= 'm' && c <= 'o') return '6';
    if (c >= 'p' && c <= 's') return '7';
    if (c >= 't' && c <= 'v') return '8';
    if (c >= 'w' && c <= 'z') return '9';
    return '1'; 
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, vector<string>> prefs, matches;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string w;
        cin >> w;
        
        string w1 = "";
        for (auto c : w) {
            w1 += get_code(c);
        }

        matches[w1].push_back(w);

        string prefix = "";
        for (char c : w1) {
            prefix += c;
            prefs[prefix].push_back(w);
        }
    }
    
    int m;
    cin >> m;
    string input = "";
    bool auto_c = false;

    while (m--) {
        char c;
        cin >> c;
        if (c == '1') {
            if (auto_c) {
                auto_c = false;
                continue;
            }

            if (input.empty()) {
                continue;
            }

            if (matches.count(input) && !matches[input].empty()) {
                cout << matches[input][0] << ' ';
            } 

            input = "";
        }
        else {
            input += c;
            auto_c = false;
            
            if (prefs.count(input) && !prefs[input].empty()) {
                if (prefs[input].size() == 1) {
                    cout << prefs[input][0] << ' ';
                    input = "";
                    auto_c = true;
                }
            }
        }
    }
    cout << '\n';
    return 0;
}
