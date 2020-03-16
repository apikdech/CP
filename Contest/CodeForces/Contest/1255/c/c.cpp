/**
 * author:  apikdech
 * created: 19.11.2019 22:53:21
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
int cnt[N], x[3], vis[N];
vector<int> adj[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	vector<int> v, ans;
	cin >> n;
	for (int i = 0; i < n-2; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> x[j];
			cnt[x[j]]++;
		}
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (j == k) continue;
				adj[x[j]].push_back(x[k]);
			}
		}
		for (int j = 0; j < 3; j++) {
			sort(adj[x[j]].begin(), adj[x[j]].end());
			adj[x[j]].erase(unique(adj[x[j]].begin(), adj[x[j]].end()), adj[x[j]].end());
		}
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 1) v.push_back(i);
	}
	int fi = v[0], la = v[1];
	vis[fi] = 1;
	int a = adj[fi][0];
	int b = adj[fi][1];
	ans.push_back(fi);
	while(true) {
		// cout << a << " " << b << "\n";
		int nxt;
		for (int i : adj[a]) {
			for (int j : adj[b]) {
				if (vis[i] || vis[j]) continue;
				if (i == j) nxt = i;
			}
		}
		if (nxt == la) {
			if (!vis[a]) ans.push_back(a);
			if (!vis[b]) ans.push_back(b);
			ans.push_back(nxt);
			break;
		}
		int ok = 0;
		vis[b] = 1;
		for (int i : adj[a]) {
			for (int j : adj[nxt]) {
				if (vis[i] || vis[j]) continue;
				if (i == j) {
					ans.push_back(b);
					ok = 1;
					b = nxt;
					break;
				}
			}
			if (ok) break;
		}
		if (ok) continue;
		vis[b] = 0;
		vis[a] = 1;
		for (int i : adj[b]) {
			for (int j : adj[nxt]) {
				if (vis[i] || vis[j]) continue;
				if (i == j) {
					ans.push_back(a);
					ok = 1;
					a = b;
					b = nxt;
					break;
				}
			}
			if (ok) break;
		}
	}
	for (int it : ans) cout << it << " ";
	return 0;
}
