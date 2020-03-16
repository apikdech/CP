/**
 * author:  apikdech
 * created: 09.02.2020 22:36:11
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;

ll x[N], y[N], mid_x, mid_y;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, ok = 1, m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  if (n & 1) return cout << "nO\n", 0;
  m = n/2;
  mid_x = x[0] + x[m];
  mid_y = y[0] + y[m];
  for (int i = 0; i < m; i++) {
    if (x[i] + x[m + i] != mid_x || y[i] + y[m + i] != mid_y) return cout << "nO\n", 0;
  }
  cout << "yEs\n";
  return 0;
}
