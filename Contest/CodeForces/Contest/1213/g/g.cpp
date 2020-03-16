/*
 * Author: apikdech
 * Time: 23:32:46 30-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;
vector<pair<int, pair<int, int>>> edges;
vector<pair<int, int>> q;
int p[N], n, m, idx = 0;
ll ans[N], cur = 0, sz[N];

void pre() {
	for (int i = 0; i < N; i++) p[i] = i, sz[i] = 1;
}

int f(int v) {
	return (v == p[v] ? v : p[v] = f(p[v]));
}

void unite(int u, int v) {
	u = f(u), v = f(v);
	if (u == v) return;
	cur += sz[u] * sz[v];
	p[v] = u;
	sz[u] += sz[v];
}

int main() {
	pre();
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n-1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({w, {u, v}});
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		q.push_back({x, i});
	}
	sort(edges.begin(), edges.end());
	sort(q.begin(), q.end());
	for (auto it : q) {
		while(idx < edges.size() && edges[idx].first <= it.first) {
			unite(edges[idx].second.first, edges[idx].second.second);
			idx++;
		}
		ans[it.second] = cur;
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i] << " \n"[i==m-1];
	}
	return 0;
}
