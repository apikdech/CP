/**
 * author:  apikdech
 * created: 13.02.2020 23:03:14
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
    ll n, m, ans = 0;
    cin >> n >> m;
    ans = (n * (n+1))/2;
    n -= m;
    m++;
    ll t = n % m;
    ll add = (n + m - 1)/m;
    ans -= t * (add * (add + 1))/2;
    t = m - n % m;
    add = n/m;
    ans -= t * (add * (add + 1))/2;
    cout << ans << "\n";
  }
  return 0;
}
