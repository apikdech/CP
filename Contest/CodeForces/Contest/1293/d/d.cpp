/**
 * author:  apikdech
 * created: 19.01.2020 22:00:20
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1e17;

vector<pair<ll, ll>> point;
int ans = 0;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll x, y, a_x, a_y, b_x, b_y;
  cin >> x >> y >> a_x >> a_y >> b_x >> b_y;
  ll t;
  pair<ll, ll> s;
  cin >> s.first >> s.second >> t;
  point.emplace_back(x, y);
  auto dist = [&](auto p1, auto p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
  };
  while(true) {
    ll nxt_x = x * a_x + b_x;
    ll nxt_y = y * a_y + b_y;
    if (nxt_x > INF || nxt_y > INF || nxt_x < 0 || nxt_y < 0) break;
    x = x * a_x + b_x;
    y = y * a_y + b_y;
    point.emplace_back(x, y);
  }
  int n = point.size();
  for (int i = 0; i < n; i++) {
    auto nxt = point[i];
    ll d = dist(nxt, s);
    if (d > t) continue;
    for (int j = 0; j <= i; j++) {
      auto nxx = point[j];
      if (dist(nxx, nxt) + d > t) continue;
      ans = max(ans, i - j + 1);
    }
    d = dist(nxt, s);
    for (int j = i; j < n; j++) {
      auto nxx = point[j];
      if (dist(nxx, nxt) + d > t) continue;
      ans = max(ans, j - i + 1);
    }
  }
  cout << ans << "\n";
  return 0;
}
