/**
 * author:  apikdech
 * created: 09.03.2020 22:46:26
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353 , N = 2e5 + 5;

ll fact[N], ifact[N];

ll powmod(ll a,ll b, ll m = MOD) {ll res=1; assert(b>=0); for(;b;b>>=1){if(b&1)res=(res*a)%m;a=(a*a)%m;}return res%m;}

ll inv(ll x) {
  return powmod(x, MOD - 2);
}

void pre() {
  fact[0] = 1LL;
  ifact[0] = 1LL;
  for (ll i = 1; i < N; i++) {
    fact[i] = fact[i-1] * i % MOD;
    ifact[i] = inv(fact[i]);
  }
}

ll ncr(ll x, ll y) {
  if (y > x || x < 0) return 0;
  ll res = fact[x];
  res = res * ifact[x-y] % MOD;
  res = res * ifact[y] % MOD;
  return res;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  pre();
  int n, m;
  cin >> n >> m;
  if (n < 3) return cout << "0\n", 0;
  ll ans = ncr(m, n-1) * (n-2) % MOD * powmod(2, n-3) % MOD;
  cout << ans << "\n";
  return 0;
}
