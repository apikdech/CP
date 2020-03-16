#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int a[105];

int main() {
	int n, ok = 1, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		if (a[i] + a[i-1] == 5) ok = 0;
		else if (a[i] + a[i-1] == 3) {
			ans += 3;
			if (i > 1 && a[i] == 2 && a[i-2] == 3) ans--;
		}
		else ans += 4;
	}
	if (!ok) return cout << "Infinite\n", 0;
	cout << "Finite\n";
	cout << ans << "\n";
	return 0;
}