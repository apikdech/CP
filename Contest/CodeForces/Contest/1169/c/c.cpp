/*
 * Author: apikdech
 * Time: 07:06:08 27-05-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 3e5 + 5;
int a[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = 0, r = m, ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1, prev = 0, ok = 0;
		for (int i = 0; i < n; i++) {
			int lf = a[i], rg = a[i] + mid;
			if (lf <= prev && prev <= rg || lf <= prev + m && prev + m <= rg) continue;
			if (lf < prev) {
				ok = 1;
				break;
			} else prev = lf;
		}
		if (ok) l = mid+1;
		else r = mid-1, ans = mid;
	}
	cout << ans << "\n";
	return 0;
}
