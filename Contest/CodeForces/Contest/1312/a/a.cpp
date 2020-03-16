/**
 * author:  apikdech
 * created: 09.03.2020 21:39:24
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
    int n, m;
    cin >> n >> m;
    if (n % m) cout << "NO\n";
    else cout << "YES\n";
  }
  return 0;
}
 