/**
 * author:  apikdech
 * created: 15.01.2020 13:22:03
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 3e5 + 5, M = 10;

int a[N][M], idx[1 << M];
int n, m;
pair<int, int> ans;

pair<int, int> cek(int x) {
  memset(idx, -1, sizeof idx);
  for (int i = 0; i < n; i++) {
    int mask = 0;
    for (int j = 0; j < m; j++) 
      if (a[i][j] >= x) mask |= 1 << j;
    idx[mask] = i + 1;
  }
  for (int i = 0; i < 1 << m; i++) 
    for (int j = 0; j < 1 << m; j++) 
      if (~idx[i] && ~idx[j] && (i | j) == (1 << m) - 1) return {idx[i], idx[j]};
  return {0, 0};
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < m; j++) 
      cin >> a[i][j];
  int l = 0, r = 1e9;
  while(l <= r) {
    int m = (l + r) >> 1;
    pair<int, int> t = cek(m);
    if (!t.first) r = m - 1;
    else l = m + 1, ans = t;
  }
  cout << ans.first << " " << ans.second << "\n";
  return 0;
}
