#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll a[N];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	ll ans = 0;
	for (int i = 0; i < m; i++) {
		ans += a[i];
	}
	cout << ans << " ";
	if (m >= n) {
		ans = 0;
		for (int i = 0; i < m; i++) {
			ans += a[i];
		}
	}
	else {
		int step = n/m, sisa = n % m, ptr = 0, cnt = 0, grup = m;
		ll mn = 1e8;
		ans = 0;
		while(sisa--) {
			mn = 1e8;
			for (int i = 0; i < step+1; i++) {
				mn = min(a[ptr++], mn);
			}
			grup--;
			ans += mn;
		}
		// printf("ans = %d\n", ans );
		while (grup--) {
			mn = 1e8;
			for (int i = 0; i < step; i++) {
				mn = min(a[ptr++], mn);
			}
			ans += mn;
			// printf("ans = %d\n", ans);
		}
	}
	cout << ans << "\n";
	return 0;
}