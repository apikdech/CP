#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, m, a[1005], ans = 1005;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	sort(a, a+m);
	for (int i = 0; i <= m - n; i++) {
		ans = min(ans, a[i+n-1] - a[i]);
	}
	cout << ans << "\n";
	return 0;
}