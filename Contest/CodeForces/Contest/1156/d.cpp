/*
 * Author: apikdech
 * Time: 20:10:54 21-05-2019
 * Last Modified: 15:36:51 22-05-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;
// vector<int> adj[N][5];
int p[N][2];
// , vis[N][5], ok[N][2];
ll sz[N][2], ans = 0;
// vector<int> v;

void pre() {
	for (int i = 0; i < N; i++) for (int j = 0; j < 2; j++) p[i][j] = i, sz[i][j] = 1;
}

int f(int v, int c) {
	return (v == p[v][c] ? v : p[v][c] = f(p[v][c], c));
}

void unite(int u, int v, int c) {
	u = f(u, c), v = f(v, c);
	if (u == v) return;
	if (sz[u][c] > sz[v][c]) swap(u, v);
	sz[v][c] += sz[u][c];
	p[u][c] = v;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		// adj[x][c].push_back(y);
		// adj[y][c].push_back(x);
		// ok[x][c] = ok[y][c] = 1;
		unite(x, y, c);
		// if (!vis[x][2] && ok[x][0] && ok[x][1]) vis[x][2] = 1, v.push_back(x);
		// if (!vis[y][2] && ok[y][0] && ok[y][1]) vis[y][2] = 1, v.push_back(y);
	}
	for (int i = 1; i <= n; i++) {
		if (i == p[i][0]) ans += sz[i][0] * (sz[i][0] - 1);
		if (i == p[i][1]) ans += sz[i][1] * (sz[i][1] - 1);
		ans += (sz[f(i, 0)][0] - 1) * (sz[f(i, 1)][1] - 1);
		// int x = f(i, 0), y = f(i, 1);
		// if (!vis[x][0]) vis[x][0] = 1, ans += (sz[x][0] * (sz[x][0] - 1));
		// if (!vis[y][1]) vis[y][1] = 1, ans += (sz[y][1] * (sz[y][1] - 1));
	}
	// for (int i = 0; i < v.size(); i++) {
	// 	int x = adj[v[i]][0][0];
	// 	ans += (sz[f(x, 0)][0] - 1) * (sz[f(v[i], 1)][1] - 1);
	// }
	cout << ans << "\n";
	return 0;
}