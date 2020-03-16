/*
 * Author: apikdech
 * Time: 22:37:56 26-05-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, a, x, b, y, ok = 0, pos_a, pos_b;
	cin >> n >> a >> x >> b >> y;
	if (x < a) x += n;
	if (y > b) y -= n;
	for (int i = a, j = b; i <= x && j >= y; i++, j--) {
		if (a == b) ok = 1;
		a++, b--;
		if (a > n) a -= n;
		if (b <= 0) b += n;
		// cerr << a << " " << b << "\n";
	}
	puts(ok ? "YES" : "NO");
	return 0;
}
