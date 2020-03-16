/**
 * author:  apikdech
 * created: 29.01.2020 21:39:20
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
    string ans = "";
    int n;
    cin >> n;
    int satu = n/2;
    if (n & 1) ans += '7', satu--;
    ans += string(satu, '1');
    cout << ans << "\n";
  }
  return 0;
}
