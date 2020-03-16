#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 3e5 + 5;
ll a[N], dp[N][3], x, ans = 0LL;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	memset(dp, 0, sizeof dp);
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i][0] = max(dp[i-1][0] + a[i], a[i]);
		dp[i][1] = max({dp[i-1][0] + a[i] * x, dp[i-1][1] + a[i] * x, a[i] * x});
		dp[i][2] = max({dp[i-1][1] + a[i], dp[i-1][2] + a[i], a[i]});
		ans = max({dp[i][0], dp[i][1], dp[i][2], ans});
	}
	cout << ans << "\n";
	return 0;
}