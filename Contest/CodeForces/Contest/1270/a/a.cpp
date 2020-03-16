/**
 * author:  apikdech
 * created: 29.12.2019 21:08:37
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
    int n, k1, k2, m1 = 0, m2 = 0;
    cin >> n >> k1 >> k2;
    for (int i = 0; i < k1; i++) {
      int x;
      cin >> x;
      m1 = max(m1, x);
    }
    for (int i = 0; i < k2; i++) {
      int x;
      cin >> x;
      m2 = max(m2, x);
    }
    if (m1 > m2) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
