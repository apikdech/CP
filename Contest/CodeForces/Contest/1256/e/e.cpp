/**
 * author:  apikdech
 * created: 04.11.2019 21:33:16
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;
const ll INF = (ll)1e18;
ll dp[N], pre[N], team[N], idx[N], val[N], ans[N];
pair<ll, ll> a[N];
vector<int> t[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		val[i] = a[i].first;
		a[i].second = i;
		dp[i] = INF;
	}
	sort(a, a+n);
	dp[0] = dp[1] = INF;
	dp[2] = a[2].first - a[0].first;
	dp[3] = a[3].first - a[0].first;
	dp[4] = a[4].first - a[0].first;
	team[2] = team[3] = team[4] = 1;
	for (int i = 5; i < n; i++) {
		if (dp[i] > dp[i-3] + a[i].first - a[i-2].first) {
			team[i] = team[i-3] + 1;
			dp[i] = dp[i-3] + a[i].first - a[i-2].first;
			pre[i] = i-3;
			idx[i] = i-2;
		}
		if (dp[i] > dp[i-4] + a[i].first - a[i-3].first) {
			team[i] = team[i-4] + 1;
			dp[i] = dp[i-4] + a[i].first - a[i-3].first;
			pre[i] = i-4;
			idx[i] = i-3;
		}
		if (dp[i] > dp[i-5] + a[i].first - a[i-4].first) {
			team[i] = team[i-5] + 1;
			dp[i] = dp[i-5] + a[i].first - a[i-4].first;
			pre[i] = i-5;
			idx[i] = i-4;
		}
	}
	cout << dp[n-1] << " " << team[n-1] << "\n";
	int ptr = n-1, x = team[n-1];
	while(ptr) {
		for (int i = idx[ptr]; i <= ptr; i++) t[x].push_back(a[i].second);
		ptr = pre[ptr];
		x--;
	}
	for (int i = 1; i <= team[n-1]; i++) {
		for (int it : t[i]) ans[it] = team[n-1] - i + 1;
	}
	for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i + 1 == n];
	return 0;
}
