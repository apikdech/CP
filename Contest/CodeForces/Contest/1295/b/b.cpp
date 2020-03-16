/**
 * author:  apikdech
 * created: 29.01.2020 22:02:10
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
    map<ll, ll> cnt;
    int n;
    ll x, bal = 0, ans = 0, last = 0, ok = 0;
    cin >> n >> x;
    string s;
    cin >> s;
    for (char &c : s) {
      if (c == '0') last++;
      else last--;
      if (last == x) ok = 1;
    }
    if (last == 0) {
      if (ok) cout << "-1\n";
      else cout << "0\n";
      continue;
    }
    if (x == 0) ans++;
    for (char c : s) {
      if (c == '0') bal++;
      else bal--;
      if (bal == x) ans++;
      else if ((x - bal) * last >= 0 && (x - bal) % last == 0) ans++;
    }
    cout << ans << "\n";
  }
  return 0;
}
