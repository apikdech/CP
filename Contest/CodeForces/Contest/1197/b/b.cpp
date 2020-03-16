/*
 * Author: apikdech
 * Time: 21:58:35 22-07-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;
int a[N], p[N], b[N];

int f(int v) {
	return (v == p[v] ? v : p[v] = f(p[v]));
}

void unite(int u, int v) {
	u = f(u), v = f(v);
	if (u == v) return;
	p[u] = v;
}

void pre() {
	for (int i = 0; i < N; i++) p[i] = i;
}

int main() {
	pre();
	ios::sync_with_stdio(0); cin.tie(0);
	int n, ok = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		b[i] = x;
		a[x] = i;
	}
	for (int i = n; i > 1; i--) {
		// cerr << f(b[a[i-1] + 1]) << " " << f(b[a[i-1] - 1]) << "\n";
		if (abs(a[i] - a[i-1]) <= 1 || f(i) == f(b[a[i-1] + 1]) || f(i) == f(b[a[i-1] - 1])) unite(i, i-1);
		else ok = 0;
	}
	if (ok) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
