/**
 * author:  apikdech
 * created: 16.01.2020 12:54:50
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
    int n;
    cin >> n;
    vector<pair<int, int>> segs;
    vector<int> ans(n+1);
    for (int i = 1; i <= n; i++) {
      int l, r;
      cin >> l >> r;
      segs.push_back({l, -i});
      segs.push_back({r, i});
    }
    sort(segs.begin(), segs.end());
    int cnt = 0, ok = 0, res = 0;
    set<int> s;
    for (auto &[pt, idx] : segs) {
      if (idx > 0) {
        ok = 1;
        s.erase(idx);
        if (s.empty()) cnt++, ok = 0;
      } else {
        if (s.size() == 1 && ok) ans[*s.begin()]++;
        s.insert(-idx);
      }
    }
    for (int i = 1; i <= n; i++) res = max(res, ans[i]);
    cout << min(res + cnt, n-1) << "\n";
  }
  return 0;
}
