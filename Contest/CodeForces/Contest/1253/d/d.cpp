/**
 * author:  apikdech
 * created: 16.11.2019 22:47:23
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;

int p[N], r[N], ans = 0;

int f(int v) {
	return (v == p[v] ? v : p[v] = f(p[v]));
}

bool unite(int u, int v) {
	u = f(u), v = f(v);
	if (u == v) return false;
	p[u] = v;
	r[v] = max(r[u], r[v]);
	return true;
}

void pre() {
	for (int i = 0; i < N; i++) p[i] = r[i] = i;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	pre();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		unite(x, y);
	}
	for (int i = 1; i < n; i++) {
		if (r[f(i)] > i && unite(i, i+1)) ans++;
	}
	cout << ans << "\n";
	return 0;
}
