#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int a[1005];

int main() {
	int n, h, ans = 0, ok = 1, x;
	cin >> n >> h;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		sort(a, a+i+1, greater<int>());
		x = h;
		for (int j = 0; j <= i; j+=2) {
			if (a[j] > x) ok = 0;
			if (j % 2 == 0) x -= a[j];
		}
		if (!ok) break;
		if (ok) ans = i+1;
	}
	cout << ans << "\n";
	return 0;
}