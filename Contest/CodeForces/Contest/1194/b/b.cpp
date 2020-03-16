/*
 * Author: apikdech
 * Time: 21:53:07 14-07-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		int n, m;
		cin >> n >> m;
		int r[m+5], c[n+5], ans = n + m - 1;
		memset(r, 0, sizeof r);
		memset(c, 0, sizeof c);
		char a[n+5][m+5];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				if (a[i][j] == '.') r[j]++, c[i]++;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans = min(ans, r[j] + c[i] - (a[i][j] == '.' ? 1 : 0));
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
