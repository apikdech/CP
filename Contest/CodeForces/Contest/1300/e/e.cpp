/**
 * author:  apikdech
 * created: 10.02.2020 06:49:39
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e6 + 5;

ll a[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<double, int>> v;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    if (v.empty()) v.push_back({x, 1});
    else if (v.back().first < x) v.push_back({x, 1});
    else {
      double t = v.back().first;
      int cnt = v.back().second;
      v[v.size() - 1].first = (t * cnt + x)/(cnt + 1);
      v[v.size() - 1].second = cnt + 1;
    }
    while(v.size() > 1 && v.back().first < v[v.size() - 2].first) {
      double t = v.back().first;
      int cnt = v.back().second;
      v.pop_back();
      v[v.size() - 1].first = (t * cnt + v.back().first * v.back().second) / (cnt + v.back().second);
      v[v.size() - 1].second = cnt + v.back().second;
    }
  }
  cout << fixed << setprecision(9);
  for (auto &[num, occ] : v) {
    for (int i = 0; i < occ; i++) cout << num << "\n";
  }
  return 0;
}
