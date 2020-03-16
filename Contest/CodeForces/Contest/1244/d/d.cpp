/*
 * Author: apikdech
 * Time: 20:35:21 14-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
ll c[3][N], res = 1e18, deg[N], ok = 1, a[N];
vector<int> ans, adj[N], path;
int st = -1;
bool vis[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c[i][j];
		}	
	}
	for (int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
		deg[x]++, deg[y]++;
		if (deg[x] > 2 || deg[y] > 2) ok = 0;
	}
	if (!ok) cout << "-1\n";
	else {
		for (int i = 0; i < n; i++) {
			if (deg[i] == 1) st = i;
		}
		queue<int> q;
		q.push(st);
		vis[st] = 1;
		path.push_back(st);
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for (int v : adj[u]) {
				if (vis[v]) continue;
				q.push(v);
				vis[v] = 1;
				path.push_back(v);
			}
		}
		vector<int> x{0, 1, 2};
		do {
			ll tmp = 0;
			for (int i = 0; i < n; i++) {
				int u = path[i];
				tmp += c[x[i%3]][u];
			}
			if (tmp < res) res = tmp, ans = x;
		} while(next_permutation(x.begin(), x.end()));
		cout << res << "\n";
		for (int i = 0; i < n; i++) {
			a[path[i]] = ans[i % 3];
		}
		for (int i = 0; i < n; i++) {
			cout << a[i]+1 << " \n"[i == n-1];
		}
	}
	return 0;
}
