#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		ans = max(ans, x+y);
	}
	cout << ans << "\n";
	return 0;
}