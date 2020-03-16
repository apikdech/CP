/**
 * author:  apikdech
 * created: 17.02.2020 23:35:24
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5, INF = 1e9;

int a[N], l[N], r[N], vis[N], ans, ok;
vector<int> adj[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  queue<int> q;
  q.push(1);
  vis[1] = 1;
  l[1] = 0;
  while(!q.empty()) {
    int v = q.front();
    q.pop();
    for (int &u : adj[v]) {
      if (vis[u]) continue;
      l[u] = l[v] + 1;
      vis[u] = 1;
      q.push(u);
    }
  }
  memset(vis, 0, sizeof vis);
  q.push(n);
  vis[n] = 1;
  r[n] = 0;
  while(!q.empty()) {
    int v = q.front();
    q.pop();
    for (int &u : adj[v]) {
      if (vis[u]) continue;
      r[u] = r[v] + 1;
      vis[u] = 1;
      q.push(u);
    }
  }
  vector<pair<int, int>> vl, vr;
  for (int i = 0; i < k; i++) {
    vl.push_back({l[a[i]], a[i]});
    vr.push_back({r[a[i]], a[i]});
  }
  sort(vl.begin(), vl.end());
  sort(vr.begin(), vr.end());
  reverse(vr.begin(), vr.end());
  for (int i = 0; i < k; i++) {
    int now = l[n] - vl[i].first;
    int idx = lower_bound(vr.begin(), vr.end(), pair<int, int>(now, -1), greater<pair<int, int>>()) - vr.begin();
    if (vr[idx].second == vl[i].second) idx++;
    if (idx == k) continue;
    ans = max(ans, vl[i].first + vr[idx].first + 1);
  }
  cout << ans << "\n";
  return 0;
}
