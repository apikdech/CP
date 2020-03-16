/**
 * author:  apikdech
 * created: 04.03.2020 16:57:03
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5, INF = 1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll a[N], ans = INF;
map<ll, int> vis;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int it = 0; it < 20; it++) {
    int pos = rng() % n;
    vector<ll> v;
    for (auto &add : {-1, 0, 1}) {
      ll num = a[pos] + add;
      if (!num) continue;
      for (ll i = 2; i * i <= num; i++) {
        int ok = 0;
        while(num % i == 0) num /= i, ok = 1;
        if (ok) v.push_back(i);
      }
      if (num > 1) v.push_back(num);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (auto &div : v) {
      if (vis.count(div)) continue;
      vis[div] = 1;
      ll cnt = 0;
      for (int i = 0; i < n; i++) {
        if (1 <= a[i] && a[i] < div) cnt += div - a[i] % div;
        else cnt += min(a[i] % div, div - a[i] % div);
      }
      ans = min(ans, cnt);
    }
  }
  cout << ans << "\n";
  return 0;
}
