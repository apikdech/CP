/*
 * Author: apikdech
 * Time: 22:30:37 16-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e3 + 5;
ll x[N], y[N], z[N];
vector<pair<ll, pair<int, int>>> dist;
bool vis[N];

ll f(ll x0, ll y0, ll z0, ll x1, ll y1, ll z1) {
	ll dx = x0 - x1;
	ll dy = y0 - y1;
	ll dz = z0 - z1;
	return dx*dx + dy*dy + dz*dz;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> z[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			dist.push_back({f(x[i], y[i], z[i], x[j], y[j], z[j]), {i+1, j+1}});
		}
	}
	sort(dist.begin(), dist.end());
	for (auto it : dist) {
		if (vis[it.second.first] || vis[it.second.second]) continue;
		vis[it.second.first] = vis[it.second.second] = 1;
		cout << it.second.first << " " << it.second.second << "\n";
	}
	return 0;
}