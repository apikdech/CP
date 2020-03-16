/**
 * author:  apikdech
 * created: 07.03.2020 17:16:03
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, cnt = 0, lst = -1, prv, ans = 0;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    char c = s[i];
    prv = cnt;
    if (c == ')') cnt--;
    else cnt++;
    if (cnt == 0) {
      // cout << i << " " << lst << "\n";
      if (prv < 0) ans += i - lst;
      lst = i;
    }
  }
  if (cnt != 0) cout << "-1\n";
  else cout << ans << "\n";
  return 0;
}
