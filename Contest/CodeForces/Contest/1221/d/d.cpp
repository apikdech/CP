/*
 * Author: apikdech
 * Time: 14:00:32 20-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 3e5 + 5;
const ll INF = 2e18;
ll a[N], b[N], dp[N][3], ans;

void reset(int n) {
	for (int i = 0; i <= n; i++) for (int j = 0; j < 3; j++) dp[i][j] = INF;
	for (int i = 0; i < 3; i++) dp[0][i] = 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		int n;
		ans = INF;
		cin >> n;
		reset(n);
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i];
			for (ll j = 0; j < 3; j++) {
				for (ll k = 0; k < 3; k++) {
					if (a[i] + j != a[i-1] + k) 
						dp[i][j] = min(dp[i][j], dp[i-1][k]);
				}
				dp[i][j] += j*b[i];
			}
		}
		for (int i = 0; i < 3; i++) ans = min(dp[n][i], ans);
		cout << ans << "\n";
	}
	return 0;
}
