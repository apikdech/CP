/**
 * author:  apikdech
 * created: 12.02.2020 23:38:39
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
    ll n, m, ans = 0, sum = 0;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i <= 60; i++) {
      if (n & 1LL << i) v.push_back(i);
    }
    vector<ll> a(m);
    for (auto &it : a) {
      cin >> it;
    }
    for (auto it : v) cout << it << " ";
    cout << "\n";
    sort(a.begin(), a.end());
    for (auto it : a) cout << it << " ";
    cout << "\n";
    int idx = 0;
    for (int i = 0, j = 0; i < v.size() && j < m; i++) {
      while(j < m && 1LL << v[i] < a[j]) j++;
      if (j == m) break;
      ans += a[j] / (1LL << v[i]);
      sum += 1LL << v[i];
    }
    if (sum == n) cout << ans << "\n";
    else cout << "-1\n";
  }
  return 0;
}
