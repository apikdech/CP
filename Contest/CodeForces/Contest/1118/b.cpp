#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 2e5 + 5;
ll a[N], x = 0, y = 0, f[N], l[N];

int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i & 1) f[i] = a[i] + f[max((i-2), 1)];
		else f[i] = a[i] + f[max((i-2), 0)];
	}
	for (int i = n; i >= 1; i--) {
		l[i] = a[i] + l[i+2];
	}
	for (int i = 1; i <= n; i++) {
		x = f[max(0, (i-2))] + l[i+1];
		y = f[max(0, (i-1))] + l[i+2];
		if (x == y) ans++;
		// } else {
		// 	x = f[max(0, (i-1))] + l[i+2];
		// 	y = f[max(0, (i-2))] + l[i+1];
		// }
	}
	cout << ans << "\n";
	return 0;
}