#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int NMAX = 1e6 + 1;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int cnt[NMAX], n, m, maks = -1, ans = 1;
		memset(cnt, 0, sizeof cnt);
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			cnt[x]++;
			maks = max(x, maks);
		}
		for (int i = maks; i > 1; i--) {
			int tot = 0;
			for (int j = i; j <= maks; j += i) {
				tot += cnt[j];
				if (tot >= m) {
					ans = i;
					break;
				}
			}
			if (ans != 1) break;
		}
		cout << ans << "\n";
	}
	return 0;
}