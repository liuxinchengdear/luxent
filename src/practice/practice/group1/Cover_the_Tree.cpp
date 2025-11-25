// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int _T; cin >> _T; while (_T -- ) {
//         int n; cin >> n;
//         vector<vector<int>> g(n + 1);
//         for (int i = 2; i <= n; i ++ ) {
//             int x; cin >> x; 
//             g[i].push_back(x); g[x].push_back(i);
//         }

//         int res = 0;
//         auto dfs = [&](auto &&self, int u, int fa) -> int {
//             if (u != 1 && g[u].size() == 1) return 0;
//             vector<int> num;
//             for (auto v : g[u]) {
//                 if (v == fa) continue;
//                 num.push_back(self(self, v, u));
//             }
//             sort(num.begin(), num.end());
//             res = max(num.back() + 1, res);
//             return (u == 1 ? num.back() : num.front()) + 1;
//         };

//         res = max(res, dfs(dfs, 1, -1));
//         cout << res << endl;
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int p[N];
void solve(){
    int n;
    cin>>n;
   vector <int> fg(n+1,0),book(n+1,0);
   for(int i=2;i<=n;++i){
       cin>>p[i];
       fg[p[i]]=1;
   }
   //fg[i] ==0  子节点,从子节点开始往上遍历
   int ans=0;
   for(int i=2;i<=n;++i){
       if(fg[i]==1){
           continue;
       }
       int len=0,id=p[i];
       while(true) {
           if (id == 0 )//根节点的父节点 p[1]==0
               break;
           if((book[id]!=0&&len + 1 >= book[id])){//遍历过且没有更优
               ans=max(ans,len+1);//这个节点到父节点之间还有一条线段，判断更优
               break;
           }
           //比原来的值更优，依然需要记录原来的值
           ans=max(ans,book[id]);
           len++;
           book[id]=len;
           id=p[id];
       }
   }
   for(int i=1;i<=n;++i){
       ans=max(ans,book[i]);
       cout<<"book"<<i<<" "<<book[i]<<"\n";
   }
    cout<<ans<<"\n";
}
int main() {
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    system("pause");
    return 0;
}