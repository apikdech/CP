/**
 * author:  apikdech
 * created: 02.11.2019 17:20:23
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e3 + 5;

int p[N];
ll x[N], y[N], c[N], k[N], ans = 0;

vector<tuple<ll, int, int>> d;
vector<int> build;
vector<pair<int, int>> edge;

ll dist(ll x1, ll y1, ll x2, ll y2) {
	ll dx = x1 - x2;
	ll dy = y1 - y2;
	return abs(dx) + abs(dy);
}

int f(int v) {
	return (v == p[v] ? v : p[v] = f(p[v]));
}

bool unite(int u, int v) {
	u = f(u), v = f(v);
	if (u == v) return false;
	p[v] = u;
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	iota(p, p + N, 0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		d.push_back({c[i], 0, i});
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ll t = dist(x[i], y[i], x[j], y[j]);
			d.push_back({t * (k[i] + k[j]), i, j});
		}
	}
	sort(d.begin(), d.end());
	for (auto &[cost, u, v] : d) {
		if (unite(u, v)) {
			ans += cost;
			if (u == 0) build.push_back(v);
			else edge.push_back({u, v});
		}
	}
	sort(build.begin(), build.end());
	cout << ans << "\n";
	cout << build.size() << "\n";
	for (int i = 0; i < (int)build.size(); i++) {
		cout << build[i] << " \n"[i + 1 == (int)build.size()];
	}
	cout << edge.size() << "\n";
	for (auto &[u, v] : edge) cout << u << " " << v << "\n";
	return 0;
}
