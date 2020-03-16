/**
 * author:  apikdech
 * created: 02.02.2020 21:08:55
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
    string s;
    int n, cnt = 0;
    cin >> n;
    cin >> s;
    string ans = "";
    for (int i = 0; i < n; i++) {
      if ((s[i] - '0') & 1) ans += s[i], cnt++;
    }
    if (cnt < 2) cout << "-1\n";
    else cout << ans[0] << ans[1] << "\n";

  }
  return 0;
}
