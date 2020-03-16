/*
 * Author: apikdech
 * Time: 21:40:45 01-06-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll a, b, c, ans = 0;
	cin >> a >> b >> c;
	ans += 2*c;
	if (a == b) ans += a + b;
	else if (a > b) ans += 2 * b + 1;
	else ans += 2 * a + 1;
	cout << ans << "\n";
	return 0;
}
