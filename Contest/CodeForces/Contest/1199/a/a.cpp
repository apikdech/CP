/*
 * Author: apikdech
 * Time: 21:35:24 30-07-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
int a[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, x, y, ans = -1;
	cin >> n >> x >> y;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		bool ok = 1;
		for (int j = 1; j <= x; j++) {
			if (a[max(i-j, 0)] < a[i]) ok = 0;
		}
		for (int j = 1; j <= y; j++) {
			if (a[min(i+j, n-1)] < a[i]) ok = 0;
		}
		if (ok) {
			ans = i+1;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
