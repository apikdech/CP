/**
 * author:  apikdech
 * created: 04.01.2020 22:42:16
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 3e5 + 5;

ll fact[N], n, m, ans = 0;

void pre() {
  fact[0] = fact[1] = 1;
  for (ll i = 2; i < N; i++) {
    fact[i] = fact[i-1] * i % m;
  }
}

ll f(ll x) {
  return fact[n-x] * fact[x] % m * (n - x + 1) % m * (n - x + 1) % m;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  pre();
  for (int i = 1; i <= n; i++) {
    ans = (ans + f(i)) % m;
  }
  cout << ans << "\n";
  return 0;
}
