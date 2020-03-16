/*
 * Author: apikdech
 * Time: 22:13:09 22-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007, N = 2e5 + 5, INF = 1e18;
ll dp[N][5];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		for (int i = 0; i < N; i++) for (int j = 0; j < 4; j++) dp[i][j] = INF;
		int n;
		ll a, b, ans = INF;
		string s;
		cin >> n >> a >> b;
		cin >> s;
		dp[0][0] = dp[0][1] = a + 2LL*b, dp[0][2] = dp[0][3] = 3LL*b + 2LL*a;
		for (int i = 1; i < n; i++) {
			if (s[i] == '1') {
				dp[i][0] = dp[i][1] = INF;
				dp[i][2] = min(dp[i-1][2], dp[i-1][3]) + 2LL*a + 2LL*b;
				dp[i][3] = min(dp[i-1][2], dp[i-1][3]) + a + 2LL*b;
			} else {
				dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + a + b;
				dp[i][1] = min(dp[i-1][2], dp[i-1][3]) + 2LL*a + b;
				dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + 2LL*a + 2LL*b;
				dp[i][3] = min(dp[i-1][2], dp[i-1][3]) + a + 2LL*b;
			}
		}
		for (int i = 0; i < 2; i++) {
			ans = min(dp[n-1][i], ans);
		}
		cout << ans << "\n";
	}
	return 0;
}
