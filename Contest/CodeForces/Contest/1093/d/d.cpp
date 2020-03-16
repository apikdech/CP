/*
 * Author: apikdech
 * Time: 22:05:57 27-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353, N = 3e5 + 5;
int vis[N], ok = 1;
ll ans = 0, cnt[2];
vector<int> adj[N];

ll powmod(ll a,ll b) {ll res=1; assert(b>=0); for(;b;b>>=1){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;}return res%MOD;}

void dfs(int u, int c) {
	vis[u] = c;
	cnt[c]++;
	for (int v : adj[u]) {
		if (vis[v] == -1) dfs(v, 1 - c);
		if ((vis[v] ^ vis[u]) == 0) ok = 0;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		ans = 1, ok = 1;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) vis[i] = -1, adj[i].clear();
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		for (int i = 1; i <= n; i++) {
			cnt[0] = cnt[1] = 0;
			if (vis[i] == -1) {
				dfs(i, 0);
				ans = (ans * (powmod(2, cnt[0]) + powmod(2, cnt[1])) % MOD) % MOD;
			}
			if (!ok) {
				cout << "0\n";
				break;
			}
		}
		if (ok) cout << ans << "\n";
	}
	return 0;
}
