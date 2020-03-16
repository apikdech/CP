/*
 * Author: apikdech
 * Time: 22:18:26 14-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
vector<int> adj[N];
int a[N], b[N], ans = 0;
bool v[N], vis[N];

void dfs(int u) {
	if (v[u]) return;
	v[u] = 1;
	for (auto x : adj[u]) {
		if (vis[x]) continue;
		if (v[a[x]] && v[b[x]]) ans++;
		vis[x] = 1;
		dfs(a[x]);
		dfs(b[x]);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> a[i] >> b[i];
		adj[a[i]].push_back(i);
		adj[b[i]].push_back(i);
	}
	for (int i = 0; i < k; i++) {
		if (vis[i]) continue;
		if (v[a[i]] && v[b[i]]) ans++;
		dfs(a[i]);
		dfs(b[i]);
	}
	cout << ans << "\n";
	return 0;
}
