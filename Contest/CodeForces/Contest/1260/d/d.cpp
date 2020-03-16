/**
 * author:  apikdech
 * created: 27.11.2019 22:28:41
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;
int a[N], cnt[N], prefmin[N], p[N], vis[N], lr[N], ans = 0, sum = 0;
vector<pair<int, int>> adj[N];

int f(int v) {
	return (v == p[v] ? v : p[v] = f(p[v]));
}

void unite(int u, int v) {
	u = f(u), v = f(v);
	if (u == v) return;
	if (u > v) swap(u, v);
	p[v] = u, lr[u] = max(lr[u], lr[v]);
}

void init(int n) {
	for (int i = 0; i <= n + 2; i++) p[i] = lr[i] = i;
	// iota(p, p+N, 0);
	// iota(lr, lr+N, 0);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int m, n, k, t;
	cin >> m >> n >> k >> t;
	init(n);
	sum = n + 1;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = N - 5; i >= 1; i--) {
		prefmin[i] = cnt[i] + prefmin[i+1];
	}
	for (int i = 0; i < k; i++) {
		int l, r, d;
		cin >> l >> r >> d;
		adj[d].push_back({l, r});
	}
	for (int i = N - 5; i >= 0; i--) {
		for (auto it : adj[i+1]) {
			int l = it.first;
			int r = it.second;
			// cout << "[" <<  l << " " << r << "]\n";
			for (int i = lr[f(l)]; i <= f(r);) {
				if (!vis[f(i)]) {
					vis[f(i)] = 1;
					sum += 2;
					if (vis[f(i-1)]) unite(i, i-1);
					if (vis[f(i+1)]) unite(i, i+1);
				}
				i = lr[f(i+1)];
			}
		}
		// cout << sum << "\n";
		if (sum <= t) ans = max(ans, prefmin[i]);
 		else break;
	}
	cout << ans << "\n";
	return 0;
}
