/**
 * author:  apikdech
 * created: 02.03.2020 13:01:27
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, ans = 0;
  cin >> n;
  string s;
  cin >> s;
  for (int c = 25; c >= 0; c--) {
    for (int it = 0; it < 100; it++) {
      int ok = 0;
      for (int i = 0; i + 1 < s.length(); i++) {
        if (s[i+1] - s[i] == 1 && s[i+1] - 'a' == c) {
          s.erase(s.begin() + i + 1);
          ans++;
          ok = 1;
        }
        else if (s[i] - s[i+1] == 1 && s[i] - 'a' == c) {
          s.erase(s.begin() + i);
          ans++;
          ok = 1;
        }
        if (ok) break;
      }
      if (!ok) break;
    }
  }
  cout << ans << "\n";
  return 0;
}
