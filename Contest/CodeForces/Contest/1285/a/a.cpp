/**
 * author:  apikdech
 * created: 10.01.2020 21:06:20
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, l = 0, r = 0;
  cin >> n;
  string s;
  cin >> s;
  for (char c : s) {
    if (c == 'L') l++;
    else r++;
  }
  cout << l + r + 1 << "\n";
  return 0;
}
