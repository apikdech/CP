/**
 * author:  apikdech
 * created: 04.03.2020 21:44:30
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
    int n;
    string s;
    cin >> n;
    cin >> s;
    string ans = s;
    int cnt = n + 1;
    for (int i = 0; i < n; i++) {
      string l = "";
      string r = "";
      for (int j = 0; j < i; j++) {
        r += s[j];
      }
      for (int j = i; j < n; j++) {
        l += s[j];
      }
      if (n % 2 == 1) {
        if (i % 2 == 0) reverse(r.begin(), r.end());
      } else if (i % 2 == 1) reverse(r.begin(), r.end());
      string res = l + r;
      if (res == ans) cnt = min(cnt, i + 1);
      else if (res < ans) ans = res, cnt = i + 1;
    }
    cout << ans << "\n";
    cout << cnt << "\n";
  }
  return 0;
}
