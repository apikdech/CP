/*
 * Author: apikdech
 * Time: 22:38:40 15-05-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 5e5 + 5;
int p[N], sz[N], n, m;

int f(int v) {
	return (v == p[v] ? v : p[v] = f(p[v]));
}

void gabung(int u, int v) {
	u = f(u), v = f(v);
	if (u == v) return;
	if (sz[u] > sz[v]) p[v] = u, sz[u] += sz[v];
	else p[u] = v, sz[v] += sz[u];
}

void pre() {
	for (int i = 0; i < N; i++) {
		p[i] = i, sz[i] = 1;
	}
}

int main() {
	pre();
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
    	int x, u, v;
    	cin >> x;
    	if (x) cin >> u;
    	for (int j = 1; j < x; j++) {
    		cin >> v;
    		gabung(u, v);
    	}
    }
    for (int i = 1; i <= n; i++) {
    	cout << sz[f(i)] << " ";
    }
    cout << "\n";
    return 0;
}
