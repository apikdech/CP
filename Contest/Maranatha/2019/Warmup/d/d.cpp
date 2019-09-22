/*
 * Author: apikdech
 * Time: 07:04:56 06-09-2019
 * Last Modified: 10:58:25 06-09-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e6 + 5;
int dp[N], a[N];

int main() {
	// ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		memset(dp, 0, sizeof dp);
		int n, ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) {
			for (int j = 2; j < 5; j++) if (i - j >= 0) 
				dp[i] = max(dp[i], dp[i-j] + a[i]), ans = max(ans, dp[i]);
		}
		printf("Case %d :%d\n", tc, ans);
	}
	// cerr << "time = " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << " ms\n";
	return 0;
}