/**
 * author:  apikdech
 * created: 24.12.2019 22:14:51
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;

pair<ll, ll> x[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		ll T, a, b, sum = 0, ans = 0, tmp = 0, ez = 0, hrd = 0, cez = 0, chrd = 0;
		cin >> n >> T >> a >> b;
		for (int i = 0; i < n; i++) {
			cin >> x[i].second;
			if (x[i].second == 0) cez++;
			else chrd++;
		}
		for (int i = 0; i < n; i++) {
			cin >> x[i].first;
		}
		sort(x, x+n);
		x[n] = {T+1, -1};
		// for (int i = 0; i < n; i++) cout << x[i].first << " " << x[i].second << "\n";
		for (int i = 0; i <= n; i++) {
			sum = ez * a + hrd * b;
			tmp = x[i].first - 1;
			tmp -= sum;
			if (tmp >= 0) {
				ll tt = min(tmp/a, cez);
				tmp -= tt*a;
				tt += min(tmp/b, chrd);
				tmp -= tt*b;
				ans = max(ans, tt + ez + hrd);
			}
			if (x[i].second == 0) ez++, cez--;
			else hrd++, chrd--;

		}
		cout << ans << "\n";
	}
	return 0;
}
