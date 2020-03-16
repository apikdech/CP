/**
 * author:  apikdech
 * created: 09.03.2020 21:49:31
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 35;

ll a[N];

vector<ll> to_base(ll x, ll k) {
  vector<ll> res;
  while(x) {
    res.push_back(x % k);
    x /= k;
  }
  while(res.size() < 60) res.push_back(0);
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    ll n, k, ok = 1;
    vector<vector<ll>> v;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      v.push_back(to_base(a[i], k));
      for (int j = 0; j < 60; j++) {
        if (v[i][j] > 1) ok = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = 0; k < 60; k++) {
          if (v[i][k] && v[j][k]) ok = 0;
        }
      }
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
