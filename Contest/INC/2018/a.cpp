#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, a[105];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int x1, x2;
	string p, q;
	cin >> x1 >> p;
	cin >> x2 >> q;
	int ans = 0;
	if (p[0] == 'r') {
		for (int i = x1-1; i < n; i++) {
			ans += a[i];
		}
	} else {
		for (int i = x1-1; i >= 0; i--) {
			ans += a[i];
		}
	}
	cout << ans << " ";
	ans = 0;
	if (q[0] == 'r') {
		for (int i = x2-1; i < n; i++) {
			if (a[i] == 0) ans++;
		}
	}
	else for (int i = x2-1; i >= 0; i--) {
		if (a[i] == 0) ans++;
	}
	cout << ans << "\n";
	return 0;
}