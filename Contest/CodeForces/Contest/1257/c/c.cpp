/**
 * author:  apikdech
 * created: 16.11.2019 20:45:54
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5, INF = 1e9;
int a[N], last[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, ans = INF;
		cin >> n;
		fill(last, last+n+1, -1);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			if (last[a[i]] != -1) ans = min(ans, i - last[a[i]] + 1), last[a[i]] = i;
			else last[a[i]] = i;
		}
		if (ans == INF) cout << "-1\n";
		else cout << ans << "\n";
	}
	return 0;
}
