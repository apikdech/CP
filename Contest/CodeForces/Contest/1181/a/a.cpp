/*
 * Author: apikdech
 * Time: 16:38:23 16-06-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll x, y, z;
	cin >> x >> y >> z;
	if (x % z == 0 || y % z == 0) cout << (x/z + y/z) << " " << 0 << "\n";
	else {
		if ((x+y)/z == x/z + y/z) cout << (x+y)/z << " 0\n";
		else cout << (x+y)/z << " " << min(z - x%z, z - y%z) << "\n";
	}
	return 0;
}


