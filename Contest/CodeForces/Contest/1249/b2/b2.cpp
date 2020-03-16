/*
 * Author: apikdech
 * Time: 21:42:09 22-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;

int p[N], sz[N];

int f(int v) {
	return (v == p[v] ? v : p[v] = f(p[v]));
}

void unite(int u, int v) {
	u = f(u), v = f(v);
	if (u == v) return;
	if (sz[u] > sz[v]) p[v] = u, sz[u] += sz[v];
	else p[u] = v, sz[v] += sz[u];
}

void pre(int n) {
	for (int i = 0; i <= n; i++) p[i] = i, sz[i] = 1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		int n;
		cin >> n;
		pre(n);
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			if (i == x) continue;
			unite(i, x);
		}
		for (int i = 1; i <= n; i++) {
			cout << sz[f(i)] << ' ';
		}
		cout << "\n";
	}
	return 0;
}
