/**
 * author:  apikdech
 * created: 27.12.2019 22:48:24
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353, N = 1e6 + 5;

ll k[N], cnt[N], x = 0, y = 1;
vector<int> a[N];

ll powmod(ll a,ll b, ll m = MOD) {ll res=1; assert(b>=0); for(;b;b>>=1){if(b&1)res=(res*a)%m;a=(a*a)%m;}return res%m;}
ll inv(ll a) {
  return powmod(a, MOD-2);
}

ll lcm(ll a, ll b) {
  return a * inv(__gcd(a, b)) % MOD * b % MOD;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
  ll n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k[i];
    for (int j = 0; j < k[i]; j++) {
      int t;
      cin >> t;
      a[i].push_back(t);
      cnt[t]++;
    }
  }
  for (int i = 0; i < n; i++) {
    ll tmp_x = 0, tmp_y = 1;
    tmp_y = tmp_y * inv(n) % MOD;
    tmp_y = tmp_y * inv(n) % MOD;
    tmp_y = tmp_y * inv(k[i]) % MOD;
    for (auto it : a[i]) {
      tmp_x += cnt[it];
    }
    ll LCM = lcm(inv(tmp_y), inv(y));
    tmp_x = tmp_x * LCM % MOD * tmp_y % MOD;
    x = x * LCM % MOD * y % MOD;
    x = (x + tmp_x) % MOD;
    y = inv(LCM);
  }
  cout << x * y % MOD << "\n";
	return 0;
}
