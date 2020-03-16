#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 1e5 + 5;
int p[N], sz[N], vis[N], u, v, x, t;
ll ans = 0, n, k;

void pre() {
	for(int i = 0; i < N; i++) {
		p[i] = i, sz[i] = 1;
	}
}

int find(int v) {
	return (v == p[v] ? v : p[v] = find(p[v]));
}

void gabung(int u, int v) {
	u = find(p[u]), v = find(p[v]);
	if (sz[u] > sz[v]) p[v] = u, sz[u] += sz[v];
	else p[u] = v, sz[v] += sz[u];
}

ll powmod(ll a,ll b) {ll res=1; assert(b>=0); for(;b;b>>=1){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;}return res%MOD;}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	cin >> n >> k;
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v >> x;
		if (!x) gabung(u, v);
	}
	ans = powmod(n, k);
	for (int i = 1; i <= n; i++) {
		t = find(p[i]);
		if (!vis[t]) {
			ans -= powmod(sz[t], k);
			if (ans < 0) ans += MOD;
			vis[t] = 1;
		}
	}
	cout << ans << "\n";
	return 0;
}