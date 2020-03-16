/**
 * author:  apikdech
 * created: 01.11.2019 06:48:23
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e6 + 5;

int a[N], cnt[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, k, d;
		cin >> n >> k >> d;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int sum = 0, ans = 0, tmp = 0;
		for (int i = 0; i < d; i++) {
			cnt[a[i]]++;
			if (cnt[a[i]] == 1) ans++;
		}
		tmp = ans;
		for (int i = d; i < n; i++) {
			cnt[a[i]]++;
			if (cnt[a[i]] == 1) tmp++;
			cnt[a[i-d]]--;
			if (!cnt[a[i-d]]) tmp--;
			ans = min(ans, tmp);
			// cout << cnt[a[i]] << " " << cnt[a[i-d]] << " " << i << " " << ans << "\n";
		}
		cout << ans << "\n";
		for (int i = 0; i < n; i++) cnt[a[i]] = 0;
	}
	return 0;
}