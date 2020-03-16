/**
 * author:  apikdech
 * created: 03.03.2020 22:36:30
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1005;

vector<int> adj[N];
int deg[N], vis[N], p[N];
set<int> v;

int ask(int u, int v) {
  int res;
  cout << "? " << u << " " << v << endl;
  cin >> res;
  return res;
}

void removeNode(int node) {
  deg[node]--;
  for (int &v : adj[node]) if (deg[v]) deg[v]--;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n-1; i++) {
    int x, y;
    cin >> x >> y;
    deg[x]++;
    deg[y]++;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) v.insert(i);
  while(true) {
    vector<int> leaves;
    for (int i = 1; i <= n; i++) {
      if (deg[i] == 1) leaves.push_back(i);
    }
    if (leaves.empty()) {
      return cout << "! " << *v.begin() << "\n", 0;
    }
    int lca = ask(leaves[0], leaves[1]);
    if (lca == leaves[0] || lca == leaves[1]) {
      return cout << "! " << lca << "\n", 0;
    }
    removeNode(leaves[0]);
    removeNode(leaves[1]);
    v.erase(leaves[0]);
    v.erase(leaves[1]);
  }
  return 0;
}
