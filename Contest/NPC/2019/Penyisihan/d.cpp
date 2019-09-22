/*
 * Author: apikdech
 * Time: 08:44:39 22-09-2019
 * Last Modified: 18:24:41 22-09-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
ll p[N], r[N], a[N], ans = 0;
pair<ll, ll> x[N], y[N];
vector<pair<ll, pair<ll, ll>>> dist;

ll f(ll v) {
	return (v == p[v] ? v : p[v] = f(p[v]));
}

void unite(ll u, ll v) {
	u = f(u), v = f(v);
	if (r[u] > r[v]) p[v] = u;
	else p[u] = v, r[v]++;
}

void pre() {
	for (int i = 0; i < N; i++) p[i] = i, r[i] = 0;
}

int main() {
	pre();
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++) {
		cin >> x[i].first >> y[i].first;
		x[i].second = y[i].second = i;
	}
	sort(x, x+n);
	sort(y, y+n);
	for (ll i = 0; i < n-1; i++) {
		dist.push_back({x[i+1].first - x[i].first, {x[i+1].second, x[i].second}});
		dist.push_back({y[i+1].first - y[i].first, {y[i+1].second, y[i].second}});
	}
	sort(dist.begin(), dist.end());
	for (auto it : dist) {
		ll u = it.second.first, v = it.second.second;
		u = f(u), v = f(v);
		if (u == v) continue;
		ans += it.first;
		unite(u, v);
	}
	cout << ans << "\n";
	// cerr << "time = " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << " ms\n";
	return 0;
}