/*
 * Author: apikdech
 * Time: 21:54:50 22-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 55;
int a[N][N], b[N][N];
vector<pair<int, int>> ans;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, ok = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			b[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 0) continue;
			if (a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1]) {
				b[i][j] = b[i+1][j] = b[i][j+1] = b[i+1][j+1] = 1;
				ans.push_back({i, j});
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] != b[i][j]) return cout << "-1\n", 0;
		}
	}
	cout << ans.size() << "\n";
	for (auto it : ans) cout << it.first << " " << it.second << "\n";
	return 0;
}
