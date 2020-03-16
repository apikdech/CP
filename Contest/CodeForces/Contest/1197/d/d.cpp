/*
 * Author: apikdech
 * Time: 23:43:45 22-07-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 3e5 + 5;
ll a[N], dp[N], cnt[N], ans = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (dp[i-1] + a[i] > a[i]) dp[i] = dp[i-1] + a[i], cnt[i] = cnt[i-1] + 1;
		else dp[i] = a[i], cnt[i] = 1;
		ans = max(ans, dp[i] - k * ((cnt[i] + m - 1)/m));
	}
	cout << ans << "\n";
	return 0;
}
