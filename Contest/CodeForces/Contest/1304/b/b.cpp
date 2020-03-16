/**
 * author:  apikdech
 * created: 15.02.2020 20:09:30
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int n, m;

bool is_palindrome(string s) {
  for (int i = 0; i < m; i++) if (s[i] != s[m-i-1]) return false;
  return true;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  string ans = "", mid = "";
  set<string> S;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (is_palindrome(s)) mid = s;
    string rs = s;
    reverse(rs.begin(), rs.end());
    if (S.count(rs)) ans += s;
    else S.insert(s);
  }
  string rans = ans;
  reverse(rans.begin(), rans.end());
  ans += mid + rans;
  cout << ans.length() << "\n";
  cout << ans << "\n";
  return 0;
}
