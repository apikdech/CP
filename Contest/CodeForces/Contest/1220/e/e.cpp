/*
 * Author: apikdech
 * Time: 15:05:33 19-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;
vector<int> adj[N];
ll deg[N], dist[N], a[N], ans = 0, d = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, s;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {	
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cin >> s;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		deg[i] = adj[i].size();
		if (deg[i] == 1 && i != s) q.push(i);
	}
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		deg[u] = -1;
		for (int v : adj[u]) {
			if (deg[v] < 0) continue;
			deg[v]--;
			dist[v] = max(dist[v], dist[u] + a[u]);
			if (deg[v] == 1 && v != s) q.push(v);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (deg[i] < 0) continue;
		ans += a[i];
		d = max(d, dist[i]);
	}
	cout << ans + d << "\n";
	return 0;
}
