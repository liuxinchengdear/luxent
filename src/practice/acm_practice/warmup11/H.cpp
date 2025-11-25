#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, res;
    getline(cin, s);
    stringstream ss(s);

    string word;
    while (ss >> word) {
        transform(word.begin(), word.end(), word.begin(), [](char ch) -> char {
            return tolower(ch);
        });
        res += word;
    }
    if (res.substr(res.size() - 12) == "isallyouneed") cout << "Yes\n" << res.substr(0, res.size() - 12) << '\n';
    else cout << "No\n";
}