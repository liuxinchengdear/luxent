#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
long long f(long long x ,long long y){
    return (x&y)*(x|y)*(x^y);
}
const int N=1e6+5;
int num[N];
const int mod=998244353;
int main() {
    int n,m,x,y;
    // cin>>n>>m;
    // for(int i=1;i<=m;++i){
    //     cin>>x>>y;
    //     num[x]++;
    //     num[y]++;
    // }
    // long long ans=0;
    // for(int i=1;i<=n;++i){
    //     for(int j=i+1;j<=n;++j){
    //         ans=(ans+f(num[i],num[j]))%mod;
    //     }
    // }
    // cout<<ans<<"\n";
    //cout<<f(7,21)<<"\n";5
    //cout<<f(7,23)<<"\n";
    //cout<<f(7,44);
    cin >> n >> m;
    cout << max(n, m) - ((max(n, m) - min(n, m)) / (min(n, m) + 1));
  return 0;
}
