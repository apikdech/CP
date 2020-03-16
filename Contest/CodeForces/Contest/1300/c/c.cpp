/**
 * author:  apikdech
 * created: 09.02.2020 21:47:24
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;

int cnt[30];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, idx = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < 30; j++) {
      if (a[i] & 1 << j) cnt[j]++;
    }
  }
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    int res = 0;
    for (int j = 0; j < 30; j++) {
      if (a[i] & 1 << j && cnt[j] == 1) res += 1 << j;
    }
    if (res) v.push_back({res, i});
  }
  sort(v.rbegin(), v.rend());
  if (!v.empty()) idx = v[0].second;
  vector<int> ans;
  ans.push_back(a[idx]);
  for (int i = 0; i < n; i++) {
    if (i == idx) continue;
    else ans.push_back(a[i]);
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i + 1 ==n];
  return 0;
}
