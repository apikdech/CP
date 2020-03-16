/**
 * author:  apikdech
 * created: 12.02.2020 22:19:02
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
    vector<int> v(26);
    vector<char> ans(60, 0);
    int pos = 27, ok = 1;
    cin >> s;
    int n = s.length();
    ans[pos] = s[0];
    v[s[0] - 'a'] = 1;
    for (int i = 1; i < n; i++) {
      int now = s[i] - 'a';
      if (v[now]) {
        if (ans[pos + 1] == s[i]) pos++;
        else if (ans[pos - 1] == s[i]) pos--;
        else {
          cout << "NO\n";
          ok = 0;
          break;
        }
      } else {
        if (!ans[pos + 1]) pos++;
        else if (!ans[pos - 1]) pos--;
        else {
          cout << "NO\n";
          ok = 0;
          break;
        }
        ans[pos] = s[i];
        v[now] = 1;
      }
      if (!ok) continue;
      cout << "YES\n";
      pos = 0;
      // while(!ans[pos]) pos++;
      for (int i = 0; i < 60; i++) cout << ans[i] << " \n"[i + 1 == 60];
      // for (int i = 0; i < 26; i++) if (!v[i]) ans[--pos] = i + 'a';
      // for (int i = 0; i < 26; i++) cout << ans[pos + i];
      cout << "\n";
    }
  }
  return 0;
}
