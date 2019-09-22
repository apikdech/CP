/*
 * Author: apikdech
 * Time: 11:52:32 05-09-2019
 * Last Modified: 12:35:36 05-09-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 505;
char a[N][N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m, ok = 1, cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
	if (n > 2 && m > 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i == 1 && j == 1 || i == n && j == 1 || i == 1 && j == m || i == n && j == m) continue;
				else if (i > 1 && i < n && j > 1 && j < m) if (a[i][j] == '.') cnt++;
			}
		}
		for (int i = 2; i < n; i++) if (a[i][1] == '#' || a[i][m] == '#') ok = 0;
		for (int j = 2; j < m; j++) if (a[1][j] == '#' || a[n][j] == '#') ok = 0;
		cout << cnt + ok << "\n";
	} else if (n <= 2 && m <= 2) cout << "0\n";
	else {
		if (n == 1) {
			for (int j = 2; j < m; j++) if (a[1][j] == '.') cnt++;
		}
		else if (n == 2) {
			for (int j = 2; j < m; j++) if (a[1][j] == '.' && a[2][j] == '.') cnt++;
		}
		else if (m == 2) {
			for (int i = 2; i < n; i++) if (a[i][1] == '.' && a[i][2] == '.') cnt++;
		}
		else for (int i = 2; i < n; i++) if (a[i][1] == '.') cnt++;
		cout << cnt << "\n";
	}
	// cerr << "time = " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << " ms\n";
	return 0;
}