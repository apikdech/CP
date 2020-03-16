#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int n, x, mx = 0, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		mx = max(x, mx);
		if (i == mx) ans++;
	}
	cout << ans << "\n";
	return 0;
}