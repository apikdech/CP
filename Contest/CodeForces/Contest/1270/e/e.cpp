/**
 * author:  apikdech
 * created: 29.12.2019 23:24:02
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e3 + 5;

ll x[N], y[N];
vector<int> ans;

ll dist(ll x1, ll y1, ll x2, ll y2) {
  ll dx = x1-x2;
  ll dy = y1-y2;
  return dx*dx + dy*dy;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  ll g = 0;
  for (int i = 1; i < n; i++) {
    g = __gcd(g, dist(x[0], y[0], x[i], y[i]));
  }
  for (int i = 0; i < n; i++) {
    if (dist(x[0], y[0], x[i], y[i])/g & 1) ans.push_back(i+1);
  }
  cout << ans.size() << "\n";
  for (auto it : ans) cout << it << " ";
  return 0;
}
