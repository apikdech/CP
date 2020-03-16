/*
 * Author: apikdech
 * Time: 20:10:49 11-06-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 505;
char a[N][N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, ok = 1, xx, yy;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == a[i+1][j] && a[i][j] == a[i-1][j] && a[i][j] == a[i][j+1] && a[i][j] == a[i][j-1] && a[i][j] == '*') q.push({i, j});
		}
	}
	if (q.size() > 1 || q.empty()) return cout << "NO\n", 0;
	int x = q.front().first;
	int y = q.front().second;
	// cerr << x << " " << y  << "\n";
	xx = x-1, yy = y-1;
	q.pop();
	while(xx > 0 && a[xx][y] == '*') {
		// cerr << xx << "\n";
		a[xx][y] = '.', xx--;
	}
	xx = x+1;
	while(xx <= n && a[xx][y] == '*') {
		// cerr << xx << "\n";
		a[xx][y] = '.', xx++;
	}
	while(yy > 0 && a[x][yy] == '*') a[x][yy] = '.', yy--;
	yy = y+1;
	while(yy <= m && a[x][yy] == '*') a[x][yy] = '.', yy++;
	a[x][y] = '.';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == '*') ok = 0;
			// cout << a[i][j];
		}
		// cout << "\n";
	}
	if (!ok) cout << "NO\n";
	else cout << "YES\n";
	return 0;
}
