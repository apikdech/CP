/*
 * Author: apikdech
 * Time: 22:40:14 22-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;
const ll INF = 1e18;
ll dp[N][2], a[N], b[N];

void pre() {
	for (int i = 0; i < N; i++) dp[i][0] = dp[i][1] = INF;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, c;
	cin >> n >> c;
	pre();
	for (int i = 1; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		cin >> b[i];
	}
	dp[1][0] = 0;
	dp[1][1] = c;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = min(dp[i-1][0] + a[i-1], dp[i-1][1] + a[i-1]);
		dp[i][1] = min(dp[i-1][0] + c + b[i-1], dp[i-1][1] + b[i-1]);
	}
	for (int i = 1; i <= n; i++) {
		cout << min(dp[i][0], dp[i][1]) << " ";
	}
	return 0;
}
