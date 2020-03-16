/*
 * Author: apikdech
 * Time: 22:22:46 15-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int a1, a2, k1, k2, n, mn = 0, mx = 0, x = 0, y = 0;
	cin >> a1 >> a2 >> k1 >> k2 >> n;
	x = n - a1*(k1-1) - a2*(k2-1);
	if (k2 < k1) swap(k1, k2), swap(a1, a2);
	if (k1 <= k2) mx = min(a1, n/k1), n -= a1*k1, mx += max(0, min(a2, n/k2));
	mn = max(0, x);
	cout << mn << " " << mx << "\n";
	return 0;
}
