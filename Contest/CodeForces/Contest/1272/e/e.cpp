/**
 * author:  apikdech
 * created: 12.12.2019 21:42:39
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;

int a[N], vis[N], d[N], n;

int dfs(int v) {
	if (vis[v]) return d[v];
	vis[v] = 1;
	if (v + a[v] <= n && a[v] & 1 != a[v + a[v]] & 1) {
		d[v]++;
		return d[v];
	}
	if (v - a[v] >= 1 && a[v] & 1 != a[v - a[v]] & 1) {
		d[v]++;
		return d[v];
	}
	int ret = MOD;
	if (v + a[v] > n && v - a[v] < 1) {
		d[v] = -1;
		return -1;
	}
	if (v + a[v] <= n) ret = min(ret, 1 + dfs(v + a[v]));
	if (v - a[v] >= 1) ret = min(ret, 1 + dfs(v - a[v]));
	d[v] = ret;
	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		d[i] = MOD;
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		d[i] = dfs(i);
		vis[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		cout << d[i] << " \n"[i == n];
	}
	return 0;
}
