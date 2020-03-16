/*
 * Author: apikdech
 * Time: 07:27:37 20-06-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5, INF = 1e9;
int a[N], cmx = 0, mx = 0;
map<int, int> m, idx;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, ans = -1, cnt = 0, c = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		idx[a[i]] = i+1;
	}
	sort(a, a+n);
	for (int i = 1; i < n; i++) {
		m[a[i] - a[i-1]]++;
		if (cmx < m[a[i] - a[i-1]]) cmx = m[a[i] - a[i-1]];
	}
	if (m.size() > 3) ans = -1;
	else if (m.size() == 1 || n <= 3) ans = 1;
	else {
		for (auto it : m) {
			if (it.second != cmx) continue;
			mx = it.first;
			c = mx;
			int tans = 0, st = a[0];
			for (int i = 1; i < n; i++) {
				if (st + c == a[i]) c += mx;
				else {
					if (tans != 0) {
						tans = -1;
						break;
					}
					if (i == 1) {
						if (a[0] + c == a[2]) tans = i+1;
						else tans = i, st = a[1];
					}
					else tans = i+1;
				}
			}
			ans = max(ans, tans);
		}
	}
	if (ans != -1) cout << idx[a[ans-1]] << "\n";
	else cout << ans << "\n";
	return 0;
}
