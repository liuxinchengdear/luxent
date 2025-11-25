// #include  <bits/stdc++.h>
// using namespace std;

// const int N = 5000010;

// int son[N][26], cnt[N], idx;

// void insert(string s) {
//     int p = 0;
//     for (int i = 0; i < s.size(); i ++ ) {
//         if (!isalpha(s[i])) break;
//         auto t = tolower(s[i]) - 0x61;
//         if (!son[p][t]) son[p][t] = ++ idx;
//         p = son[p][t];
//     }
//     cnt[p] ++ ;
// }

// bool query(string s) {
//     int p = 0;
//     for (int i = 0; i < s.size(); i ++ ) {
//         if (!isalpha(s[i])) break;
//         auto t = son[p][tolower(s[i]) - 0x61];
//         if (!t) return false;
//         p = t;
//     }
//     return cnt[p];
// }

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     string line;
//     getline(cin, line); 
//     stringstream ss;
//     ss.str(line);

//     int n; cin >> n;
//     for (int i = 0; i < n; i ++ ) {
//         string s; cin >> s;
//         insert(s);
//     }

//     string word;
//     int cnt = 0;
//     while (ss >> word) cnt += !query(word), insert(word);

//     cout << cnt << '\n';

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line; getline(cin, line);
    stringstream ss(line);

    int n; cin >> n;
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i ++ ) {
        string s; cin >> s; 
        mp[s] ++ ;
    }

    string word; 
    int cnt = 0;
    while (ss >> word) {
        word[0] = tolower(word[0]);
        if (!isalpha(word.back())) word.pop_back();

        cnt += !mp.count(word); mp[word] ++ ;
    }
    cout << cnt << endl;
    return 0;
}