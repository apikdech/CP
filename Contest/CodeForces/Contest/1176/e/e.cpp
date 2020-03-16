/*
 * Author: apikdech
 * Time: 22:38:06 09-06-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;
int vis[N], t;
vector<int> adj[N], odd, even;

void dfs(int u, int dist) {
	vis[u] = t;
	if (dist & 1) odd.push_back(u);
	else even.push_back(u);
	for (auto v : adj[u]) if (vis[v] != t) dfs(v, dist + 1);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	memset(vis, -1, sizeof vis);
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) adj[i].clear();
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		odd.clear();
		even.clear();
		dfs(1, 0);
		if (odd.size() < even.size()) {
			cout << odd.size() << "\n";
			for (int i = 0; i < odd.size(); i++) cout << odd[i] << " \n"[i == odd.size()-1];
		} else {
			cout << even.size() << "\n";
			for (int i = 0; i < even.size(); i++) cout << even[i] << " \n"[i == even.size()-1];
		}
	}
	return 0;
}
