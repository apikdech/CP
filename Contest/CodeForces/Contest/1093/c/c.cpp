/*
 * Author: apikdech
 * Time: 21:22:04 27-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;
ll a[N], mx = 0, mn = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n/2; i++) {
		ll b;
		cin >> b;
		if (i == 0) mx = b, a[i] = 0, a[n-i-1] = b;
		else if (b >= mx) a[i] = b - mx, a[n-i-1] = mx, mn = max(mn, a[i]);
		else mx = b, a[i] = 0, a[n-i-1] = b;
		if (a[i] < mn)  a[n-i-1] -= mn - a[i], a[i] += mn - a[i], mx = min(mx, a[n-i-1]);
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " \n"[i==n-1];
	}
	return 0;
}
