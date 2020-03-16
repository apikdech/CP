#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll a, b, x, y;
	cin >> a >> b >> x >> y;
	ll div = __gcd(x, y);
	x /= div;
	y /= div;
	cout << min(a/x, b/y) << "\n";
	return 0;
}