/**
 * author:  apikdech
 * created: 04.02.2020 21:35:28
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
    int n, genap = 0, ganjil = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x & 1) ganjil++;
      else genap++;
    }
    if (genap && ganjil || ganjil & 1) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
