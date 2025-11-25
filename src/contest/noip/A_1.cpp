#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

const int p = 998244353;

int T, id, n, m, c, f;

int main() {
  for (std::cin >> T >> id; T; --T) {
    std::cin >> n >> m >> c >> f;
    std::vector<std::string> a(n);
    std::vector<std::vector<int>> right(n), up(n), down(n);
    for (auto &u : right) u.resize(m + 1);
    for (auto &u : up) u.resize(m + 1);
    for (auto &u : down) u.resize(m + 1);
    std::generate_n(a.begin(), n, []() -> std::string { std::string s; std::cin >> s; return s; });
    int ans1 = 0, ans2 = 0;
    for (int i = n - 1; i; --i) {
      for (int j = 0; j < m; ++j) if (a[i][j] != '1') {
        if (i < n - 1) down[i][j] = down[i + 1][j] + 1;
        else down[i][j] = 1;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = m - 1; j >= 0; --j) if (a[i][j] != '1') {
        right[i][j] = right[i][j + 1] + 1;
        if (i > 1 && a[i - 1][j] != '1' && right[i - 2][j] > 0) up[i][j] = up[i - 1][j] + right[i - 2][j] - 1;
        int c = (right[i][j] - 1) * up[i][j] % p, f = 1ll * c * (down[i][j] - 1) % p;
        if ((ans1 += c) >= p) ans1 -= p;
        if ((ans2 += f) >= p) ans2 -= p;
      }
    }
    std::cout << ans1 * c << ' ' << ans2 * f << '\n';
  }
}
