/**
 * author:  apikdech
 * created: 10.01.2020 21:45:36
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

ll cek(ll x) {
  for (ll i = 2; i * i <= x; i++)  {
    if (x % i == 0) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll x;
  cin >> x;
  if (cek(x)) cout << 1 << " " << x << '\n';
  else {
    vector<ll> v;
    ll mul = x;
    for (ll i = 2; i * i <= x; i++) {
      ll tmp = 1;
      while(x % i == 0) {
        x /= i;
        tmp *= i;
      }
      if (tmp != 1) v.push_back(tmp);
    }
    if (x > 1) v.push_back(x);
    sort(v.begin(), v.end());
    int n = v.size();
    ll mn = mul, l = 1, r = mul;
    for (int i = 0; i < (1 << n); i++) {
      ll t = 1;
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) t *= v[j];
      }
      if (mn > max(t, mul/t)) mn = max(t, mul/t), l = t, r = mul/t;
    }
    cout << l << " " << r << "\n";
  }
  return 0;
}