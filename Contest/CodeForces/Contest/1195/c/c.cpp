/*
 * Author: apikdech
 * Time: 22:23:32 17-07-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
ll a[N], b[N], dp[N][5];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	dp[0][0] = dp[0][1] = 0;
	for (int i = 1; i <= n; i++) {
		if (i > 1) dp[i][0] = a[i] + max({dp[i-1][1], dp[i-2][0], dp[i-2][1]}), 
					dp[i][1] = b[i] + max({dp[i-1][0], dp[i-2][0], dp[i-2][1]});
		else dp[i][0] = a[i] + dp[i-1][1], dp[i][1] = b[i] + dp[i-1][0];
	}
	cout << max(dp[n][0], dp[n][1]) << "\n";
	return 0;
}
