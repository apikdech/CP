/*
 * Author: apikdech
 * Time: 21:51:47 20-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll n, l, r, sumL = 0, sumR = 0, x = 1;
	cin >> n >> l >> r;
	for (int i = 0; i < l; i++) {
		sumL += x;
		x *= 2;
	}
	sumL += n-l;
	x = 1;
	for (int i = 0; i < n; i++) {
		sumR += x;
		if (r > 1) r--, x *= 2;
	}
	cout << sumL << " " << sumR << "\n";
	return 0;
}
