/*
 * Author: apikdech
 * Time: 22:54:25 15-09-2019
 * Last Modified: 23:01:56 15-09-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;
ll dp[N][5], pos = 0, neg = 0;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (i) {
			if (x > 0) dp[i][0] = dp[i-1][0] + 1, dp[i][1] = dp[i-1][1];
			else dp[i][0] = dp[i-1][1], dp[i][1] = dp[i-1][0] + 1;
		} else {
			if (x > 0) dp[i][0] = 1;
			else dp[i][1] = 1;
		}
		pos += dp[i][0];
		neg += dp[i][1];
	}
	cout << neg << " " << pos << "\n";
	// cerr << "time = " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << " ms\n";
	return 0;
}