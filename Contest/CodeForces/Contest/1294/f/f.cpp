/**
 * author:  apikdech
 * created: 22.01.2020 23:35:37
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;

int dist[N], vis[N], n, ans, l, timer, init, root;
vector<int> adj[N], tin, tout;
vector<vector<int>> up;

void dfs(int v, int p) {
  tin[v] = ++timer;
  up[v][0] = p;
  for (int i = 1; i <= l; i++) up[v][i] = up[up[v][i-1]][i-1];
  for (int &u : adj[v]) {
    if (u != p) {
      dfs(u, v);
    }
  }
  tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
  if (is_ancestor(u, v)) return u;
  if (is_ancestor(v, u)) return v;
  for (int i = l; i >= 0; i--) {
    if (!is_ancestor(up[u][i], v)) {
      u = up[u][i];
    }
  }
  return up[u][0];
}

void preprocess(int root) {
  tin.resize(n);
  tout.resize(n);
  l = ceil(log2(n));
  up.assign(n, vector<int>(l + 1));
  dfs(root, root);
}

int bfs(int v) {
  for (int i = 0; i <= n; i++) vis[i] = dist[i] = 0;
  queue<int> q;
  q.push(v);
  vis[v] = 1;
  while(!q.empty()) {
    v = q.front();
    q.pop();
    for (int &u : adj[v]) {
      if (vis[u]) continue;
      vis[u] = 1;
      dist[u] = dist[v] + 1;
      q.push(u);
    }
  }
  return int(max_element(dist, dist + n) - dist);
}

int findDiameter() {
  root = bfs(0);
  init = bfs(root);
  return dist[init];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 0; i + 1 < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  ans = findDiameter();
  preprocess(root);
  int mx = 0, idx = -1;
  for (int i = 0; i < n; i++) {
    if (i == root || i == init) continue;
    int _lca = lca(init, i);
    int tmpDist = dist[i] - dist[_lca];
    if (mx < tmpDist) mx = tmpDist, idx = i;
  }
  if (idx == -1) {
    for (int i = 0; i < n; i++) {
      if (i != root && i != init) {
        idx = i;
        break;
      }
    }
  }
  cout << ans + mx << "\n";
  cout << ++init << " " << ++root << " " << ++idx << "\n";
  return 0;
}
