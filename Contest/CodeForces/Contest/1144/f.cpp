#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 2e5 + 5;
int n, m, u, c[N], a, b;
vector<int> adj[N];
bool vis[N], ok = 1;
vector<pair<int, int>> v;

void bfs(int x) {
	queue<int> q;
	c[x] = 1;
	q.push(x);
	vis[x] = 1;
	while(!q.empty()) {
		u = q.front();
		q.pop();
		for (auto v : adj[u]) {
			if (c[v] == c[u]) ok = 0;
			if (vis[v]) continue;
			c[v] = 1-c[u];
			vis[v] = 1;
			q.push(v);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) c[i] = -1;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		v.emplace_back(a, b);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) bfs(i);
	}
	if (!ok) return cout << "NO\n", 0;
	cout << "YES\n";
	for (int i = 0; i < m; i++) {
		cout << c[v[i].first];
	}
	cout << "\n";
	return 0;
}