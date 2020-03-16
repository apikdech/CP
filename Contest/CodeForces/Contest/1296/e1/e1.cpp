/**
 * author:  apikdech
 * created: 04.02.2020 22:36:27
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s, s1 = "", s2 = "", ans = "";
  cin >> s;
  for (char &c : s) {
    if (c >= s1.back()) s1 += c, ans += '0';
    else if (c >= s2.back()) s2 += c, ans += '1';
    else return cout << "NO\n", 0;
  }
  cout << "YES\n";
  cout << ans << "\n";
  return 0;
}
