/*
 * Author: apikdech
 * Time: 06:10:14 20-06-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int a[3], d, ans = 0;
	cin >> a[0] >> a[1] >> a[2] >> d;
	sort(a, a+3);
	if (a[1] - a[0] < d) ans += d - (a[1] - a[0]);
	if (a[2] - a[1] < d) ans += d - (a[2] - a[1]);
	cout << ans << "\n";
	return 0;
}
