/**
 * author:  apikdech
 * created: 24.02.2020 21:35:11
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
    int a, b, ans = 0;
    cin >> a >> b;
    if (a == b) ans = 0;
    else if (a < b) {
      if ((b - a) & 1) ans = 1;
      else ans = 2;
    } else {
      if ((a - b) % 2 == 0) ans = 1;
      else ans = 2;
    }
    cout << ans << "\n";
  }
  return 0;
}
