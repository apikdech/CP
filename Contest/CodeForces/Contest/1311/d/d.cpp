/**
 * author:  apikdech
 * created: 24.02.2020 22:41:29
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 5e4, INF = 1e9;

vector<tuple<int, int, int>> v;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
      for (int k = j; k <= N; k += j) {
        v.push_back({i, j, k});
      }
    }
  }
  int t;
  cin >> t;
  while(t--) {
    int a, b, c, x, y, z, mn = INF;
    cin >> a >> b >> c;
    for (auto &[ta, tb, tc] : v) {
      int res = abs(ta - a) + abs(tb - b) + abs(tc - c);
      if (res < mn) mn = res, x = ta, y = tb, z = tc;
    }
    cout << mn << "\n";
    cout << x << " " << y << " " << z << "\n";
  }
  return 0;
}
