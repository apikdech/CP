/*
 * Author: apikdech
 * Time: 22:56:53 15-05-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, cnt = 0, mx = 0, r;
  cin >> n;
  string s, ans = "";
  cin >> s;
  for (int i = 0; i < n; i++) {
  	ans += "0";
  	if (s[i] == '(') cnt++;
    else cnt--;
    mx = max(cnt, mx);
  }
  // cerr << mx << "\n";
  r = mx - mx/2, cnt = 0;
  for (int i = 0; i < n; i++) {
  	if (s[i] == '(' && cnt < r) cnt++, ans[i] = '1';
  	else if (s[i] == ')' && cnt > 0) cnt--, ans[i] = '1';
  }
  cout << ans << "\n";
  return 0;
}
