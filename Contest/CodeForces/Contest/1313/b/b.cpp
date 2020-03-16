/**
 * author:  apikdech
 * created: 23.02.2020 17:16:04
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, x, y, l, r, mn, mx;
    cin >> n >> x >> y;
    if (n == 1) {
      cout << "1 1\n";
      continue;
    }
    if (x == n) l = n-1;
    else l = n;
    r = max(x + y + 1 - l, 1);
    if (r == y) r++;
    if (r < y) mn = r;
    else mn = r-1;
    if (x + y <= n) {
      if (x == 1) l = 2;
      else l = 1;
      r = x + y - l;
      if (r > y) mx = r;
      else mx = r+1;
    } else {
      if (x == n) l = n-1;
      else l = n;
      r = x + y - l;
      if (r > n) mx = n;
      int range;
      if (r > y) range = n - r;
      else range = n - r + 1;
      mx = max(r - 1 + range, mx);
    }
    cout << min(mn, n) << " " << mx << "\n";
  }
  return 0;
}
