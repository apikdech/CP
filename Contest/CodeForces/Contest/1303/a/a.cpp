/**
 * author:  apikdech
 * created: 12.02.2020 21:37:53
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
    cin >> s;
    int fi = 105, la = 0, cnt = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '1') fi = min(fi, i), la = max(la, i);
    }
    for (int i = fi; i < la; i++) {
      if (s[i] == '0') cnt++;
    }
    cout << cnt << "\n";
  }
  return 0;
}
