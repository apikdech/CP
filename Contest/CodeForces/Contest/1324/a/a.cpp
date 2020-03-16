/**
 * author:  apikdech
 * created: 12.03.2020 20:05:12
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
    int n, mx = 0, ok = 1;
    cin >> n;
    vector<int> v(n);
    for (int &it : v) {
      cin >> it;
      mx = max(mx, it);
    }
    for (int &it : v) {
      if (mx % 2 != it % 2) ok = 0;
    }
    if (!ok) cout << "NO\n";
    else cout << "YES\n";
  }
  return 0;
}
