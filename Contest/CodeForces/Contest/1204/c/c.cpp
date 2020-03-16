/*
 * Author: apikdech
 * Time: 22:16:45 20-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1000000007, N = 105, M = 1e6 + 5;
int n, m, u, prv, last = 0, dist[N][N], dis = 0, q[M];
char c;
vector<int> ans;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c;
			dist[i][j] = (c == '1' ? 1 : INF);
		}
		dist[i][i] = 0;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	ans.push_back(0);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> q[i];
		if (i == 0) continue;
		dis++;
		if (dist[q[last]][q[i]] < dis) {
			dis = 1;
			last = i-1;
			ans.push_back(last);
		}
	}
	ans.push_back(m-1);
	cout << ans.size() << "\n";
	for (int it : ans) cout << q[it] << " ";
	return 0;
}
