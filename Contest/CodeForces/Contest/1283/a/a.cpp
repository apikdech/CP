/**
 * author:  apikdech
 * created: 29.12.2019 00:06:08
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
    int h, m, ans = 24*60;
    cin >> h >> m;
    h *= 60;
    h += m;
    cout << ans - h << "\n";
  }
  return 0;
}
