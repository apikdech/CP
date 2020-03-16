/**
 * author:  apikdech
 * created: 13.02.2020 21:38:40
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
    string a, b, c;
    cin >> a >> b >> c;
    int n = a.length(), ok = 1;
    for (int i = 0; i < n; i++) {
      if (a[i] != c[i] && b[i] != c[i]) ok = 0;
    }
    if (!ok) cout << "NO\n";
    else cout << "YES\n";
  }
  return 0;
}
