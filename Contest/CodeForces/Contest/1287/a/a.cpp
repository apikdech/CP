/**
 * author:  apikdech
 * created: 05.01.2020 21:07:19
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
    int n, ok = 0, cnt = 0, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'A') ok = 1, cnt = 0;
      else cnt++;
      if (ok) ans = max(ans, cnt);
    }
    cout << ans << "\n";
  }
  return 0;
}
