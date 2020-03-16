#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 2e5 + 5;
ll ans = 0, last = 0, a[N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	reverse(a, a+n);
	last = ans = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < last) last = a[i], ans += a[i];
		else {
			if (last > 0) last--;
			ans += last;
		}
	}
	cout << ans << "\n";
	return 0;
}