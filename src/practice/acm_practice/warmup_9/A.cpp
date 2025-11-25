#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _T; cin >> _T; while (_T -- ) {
		int n; cin >> n;
		vector<vector<int>> bin(30);
		
		for (int i = 0; i < n; i ++ ) {
			int x; cin >> x; 
			for (int j = 0; x; j ++ ) {
				if (x % 2) bin[j].push_back(i);
				x >>= 1;
			}
		}
		
		auto check = [&](int x) -> bool {
		    x = x ? (x * (x + 1) >> 1) + 1 : 0;
			for (int i = 0; i < 30; i ++ ) {
				int mx = 0;
				for (int j = 0; j < bin[i].size(); j ++ ) {
					if (!j) {int tmp = bin[i][j] + (n - 1 - bin[i].back()); mx = max(tmp, mx); continue;}
					int tmp = bin[i][j] - bin[i][j - 1] - 1; mx = max(mx, tmp);
				}
				if (mx && mx >= x) return false;
			}
			return true;
		};
		
		auto binary_search = [&]() -> int {
			int l = 0, r = sqrt(n << 1) + 1;
			while (l < r) {
				int mid = l + r >> 1;
				if (check(mid)) r = mid;
				else l = mid + 1;
			}	
			return l;
		};
		
		cout << binary_search() << endl;
	}
	return 0;
}