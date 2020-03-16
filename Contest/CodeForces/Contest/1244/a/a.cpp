/*
 * Author: apikdech
 * Time: 15:06:55 16-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int a, b, c, d, k, x, y;
		cin >> a >> b >> c >> d >> k;
		x = (a + c - 1)/c;
		y = (b + d - 1)/d;
		if (x + y > k) cout << "-1\n";
		else cout << x << " " << y << '\n';
	}
	return 0;
}
