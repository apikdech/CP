/**
 * author:  apikdech
 * created: 24.12.2019 21:48:22
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;
const ll INF = 1e15;

ll a[N], dp[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll n, p, k, ans = 0, sum = 0;
		cin >> n >> p >> k;
		for (int i = 0; i <= n; i++) dp[i] = INF;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a+1, a+n+1);
		dp[0] = 0;
		dp[1] = a[1];
		for (int i = 2; i <= n; i++) {
			dp[i] = min({dp[i], dp[i-k] + a[i], dp[i-k+1] + a[i]});
		}
		for (ll i = 1; i <= n; i++) {
			if (dp[i] <= p) ans = max(ans, i);
		}
		cout << ans << "\n";
	}
	return 0;
}
