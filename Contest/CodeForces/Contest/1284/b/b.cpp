/**
 * author:  apikdech
 * created: 04.01.2020 19:28:56
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e6 + 5, M = 1e6 + 5;

ll ans = 0, n;
vector<pair<int, int>> v;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  ans = n*n;
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    vector<int> tmp(l);
    for (int &it : tmp) {
      cin >> it;
    }
    reverse(tmp.begin(), tmp.end());
    if (is_sorted(tmp.begin(), tmp.end())) v.push_back({tmp[0], tmp.back()});
  }
  sort(v.begin(), v.end());
  for (auto &[l, r] : v) {
    // cout << l << " " << r << "\n";
    ans -= v.end() - lower_bound(v.begin(), v.end(), make_pair(r, -1));
  }
  cout << ans << "\n";
  return 0;
}
