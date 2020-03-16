/*
 * Author: apikdech
 * Time: 21:41:13 09-06-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int a[105], cnt[5];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		memset(cnt, 0, sizeof cnt);
		int n, ans = 0, x;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt[a[i] % 3] ++;
		}
		ans = cnt[0];
		x = min(cnt[1], cnt[2]);
		ans += x;
		cnt[1] -= x, cnt[2] -= x;
		ans += cnt[1]/3;
		ans += cnt[2]/3;
		cout << ans << "\n";

	}
	return 0;
}
