#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ll a, b, p, q, o = 0, e, temp = 1;
	cin >> a >> b;
	e = b - a + 1;
	while(true) {
		p = a/temp, q = b/temp;
		if (q == 0) break;
		if (a % temp != 0 && p != 0) p++;
		if (p == q && q % 2 == 1) o++;
		else {
			if (p % 2 == 1 && q % 2 == 1) o++;
			o += (q-p+1)/2;
		}
		temp *= 10;
		// cout << p << " " << q << "\n";
	}
	e -= o;
	cout << o << " " << e << "\n";
	return 0;
}
