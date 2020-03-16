/**
 * author:  apikdech
 * created: 15.12.2019 16:49:09
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;
int x[N], y[N], ans[4], res = 0, idx = -1;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, sx, sy;
	cin >> n >> sx >> sy;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++) {
		if (x[i] <= sx - 1) ans[0]++;
		if (x[i] >= sx + 1) ans[1]++;
		if (y[i] <= sy - 1) ans[2]++;
		if (y[i] >= sy + 1) ans[3]++;
	}
	for (int i = 0; i < 4; i++) {
		if (ans[i] > res) {
			res = ans[i];
			idx = i;
		}
	}
	cout << res << "\n";
	if (idx == 0) cout << sx - 1 << " " << sy << "\n";
	else if (idx == 1) cout << sx + 1 << " " << sy << "\n";
	else if (idx == 2) cout << sx << " " << sy - 1 << "\n";
	else cout << sx << " " << sy + 1 << "\n";
	return 0;
}
