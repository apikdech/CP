/**
 * author:  apikdech
 * created: 14.03.2020 21:48:59
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;

vector<int> adj[N];

int diameter[N], vis[N], x[N], y[N], p[N], deg[N];
int n;
int cnt, leaves;
map<pair<int, int>, int> m;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n-1; i++) {
    cin >> x[i] >> y[i];
    if (x[i] > y[i]) swap(x[i], y[i]);
    x[i]--, y[i]--;
    adj[x[i]].push_back(y[i]);
    adj[y[i]].push_back(x[i]);
    deg[x[i]]++;
    deg[y[i]]++;
  }
  queue<int> q;
  for (int i = 0; i < n; i++) if (deg[i] == 1) {
    q.push(i);
  }
  while(!q.empty()) {
    int v = q.front();
    q.pop();
    if (vis[v]) continue;
    vis[v] = 1;
    for (int &u : adj[v]) {
      q.push(u);
      int l = min(u, v);
      int r = max(u, v);
      if (m.count({l, r})) continue;
      m[{l, r}] = cnt++;
    }
  }
  for (int i = 0; i < n-1; i++) {
    cout << m[{x[i], y[i]}] << "\n";
  }
  return 0;
}
