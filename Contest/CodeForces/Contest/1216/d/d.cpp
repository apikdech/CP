/*
 * Author: apikdech
 * Time: 14:39:15 21-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;
ll a[N], x, y, g, sum = 0, mx = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		mx = max(mx, a[i]);
	}
	for (int i = 0; i < n; i++) {
		g = __gcd(g, mx - a[i]);
	}
	y = g;
	x = (mx*n - sum)/g;
	cout << x << " " << y << "\n";
	return 0;
}
