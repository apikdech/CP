/**
 * author:  apikdech
 * created: 04.11.2019 20:28:29
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 105;
int a[N], pos[N];
bool vis[N], vvis[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		int n, idx = -1, last = 1;
		cin >> n;
		memset(vis, 0, sizeof vis);
		memset(vvis, 0, sizeof vvis);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			pos[a[i]] = i;
		}
		while(true) {
			for (int i = 1; i <= n; i++) if (!vis[i]) {
				idx = pos[i];
				vis[i] = 1;
				vvis[i-1] = 1;
				break;
			}
			for (int i = idx-1;; i--) {
				if (vvis[i] || a[i] < a[i + 1]) break;
				vis[a[i]] = vis[a[i+1]] = 1;
				vvis[i] = 1;
				swap(a[i], a[i+1]);
			}
			// cout << idx << " " << last << "\n";
			int ok = 1;
			for (int i = 1; i <= n; i++) if (!vis[i]) ok &= 0;
			if (ok) break;
		}
		for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];

	}
	return 0;
}
