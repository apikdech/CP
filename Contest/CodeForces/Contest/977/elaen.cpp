#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int p[N], r[N], edge[N], cnt[N], ans = 0;

int findSet(int x) {
	return x == p[x] ? x : (p[x] = findSet(p[x]));
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) p[i] = i, r[i] = 1;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		cnt[x]++, cnt[y]++;
		x = findSet(x), y = findSet(y);
		if (x != y) p[x] = y, r[y] += r[x];
	}
	for (int i = 1; i <= n; i++) {
		int u = findSet(i);
		if (cnt[i] == 2) edge[u]++;
		if (edge[u] == r[u]) ans++;
	}
	cout << ans << "\n";
	cerr << "time = " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << " ms\n";
	return 0;
}