/**
 * author:  apikdech
 * created: 19.11.2019 21:38:39
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
		ll a, b, x = 0, y = 0, z = 0;
		cin >> a >> b;
		if (a < b) swap(a, b);
		a -= b;
		x = a / 5;
		a -= x * 5;
		y = a / 2;
		a -= y * 2;
		z = a;
		a -= z;
		cout << x + y + z << "\n";
	}
	return 0;
}
