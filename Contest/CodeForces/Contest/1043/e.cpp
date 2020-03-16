#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 3e5+5;
pair<ll, int> a[N], b[N];
ll sumA[N], sumB[N], ansA[N], ansB[N], c[N], d[N], tc, td;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first >> b[i].first;
		a[i].second = b[i].second = i;
		c[i] = a[i].first, d[i] = b[i].first;
	}
	sort(a+1, a + n + 1);
	sort(b+1, b + n + 1);
	for (int i = 1; i <= n; i++) {
		sumA[i] = sumA[i-1] + a[i].first;
		sumB[i] = sumB[i-1] + b[i].first;
		ansA[a[i].second] = a[i].first * (n-i) + sumA[i-1];
		ansB[b[i].second] = b[i].first * (n-i) + sumB[i-1];
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		tc = min(c[u], c[v]);
		td = min(d[u], d[v]);
		// ansA[u] -= tc;
		// ansB[u] -= td;
		// ansA[v] -= tc;
		// ansB[v] -= td;
	}
	for (int i = 1; i <= n; i++) {
		cout << ansA[i] + ansB[i] << " ";
	}
	return 0;
}

/*
2 sama 1 kan 3
2 sama 3 kan 3
2 sama 4 kan 7
2 sama 5 kan 4

4 sama 1 kan 2
4 sama 2 6
4 sama 3 2
4 sama 4 8
4 sama 5 4
*/