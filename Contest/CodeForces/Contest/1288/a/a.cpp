/**
 * author:  apikdech
 * created: 14.01.2020 22:58:10
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

string cek(ll n, ll d) {
  for (ll i = 0; i * i <= d; i++) {
    if (i + (d + i)/(i + 1) <= n) return "YES\n";
  }
  return "NO\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    ll n, d;
    cin >> n >> d;
    cout << cek(n, d);
  }
  return 0;
}
