/*
 * Author: apikdech
 * Time: 10:48:58 20-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007, N = 1e5 + 5, INF = 1e9;
vector<int> adj[N];
int dist[N], cnt[60], ans = INF;
ll a[N];

void bfs(int v) {
	for(int i = 0; i < N; i++) dist[i] = N;
	queue<int> q;
	q.push(v);
	dist[v] = 0;
	while(!q.empty()) {
		v = q.front();
		q.pop();
		for (int u : adj[v]) {
			if (dist[u] == N) {
				dist[u] = dist[v] + 1;
				q.push(u);
			} else if (dist[u] >= dist[v]) ans = min(ans, dist[u] + dist[v] + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, ok = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			i--, n--;
			continue;
		}
		for (int j = 0; j < 60; j++) {
			if ((a[i] >> j) & 1LL) cnt[j]++;
			if (cnt[j] >= 3) ok = 1;
		}
	}
	if (ok) return cout << "3\n", 0;
	if (n > 120) throw;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (a[i] & a[j]) adj[i].push_back(j);
		}
	}
	for (int i = 0; i < n; i++) {
		bfs(i);
	}
	if (ans == INF) ans = -1;
	cout << ans << "\n";
	return 0;
}
