#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, m, k, ans, div;
	cin >> n >> m >> k;
	ans = n*m;
	div = __gcd(ans, k);
	ans /= div;
	k /= div;
	if (k != 1 && k != 2) return cout << "NO\n", 0;
	//cout << "YES\n";
	int x1 = ans*2, x2 = 0, y1 = 0, y2 = 1;
	bool flag = false;
	for (int i = sqrt(ans); i > 0; i--) {
		if (x1 % i == 0) {
			x1 /= i;
			y2 *= i;
		}
		if (x1 > n || y2 > m) {
			x1 *= i;
			y2 /= i;
		} else {
			flag = true;
			break;
		}
	}
	if (!flag) return cout << "NO\n", 0;
	else {
		cout << "YES\n";
		cout << "0 0\n";
		cout << x1 << " " << y1 << "\n";
		cout << x2 << " " << y2 << "\n";
	}
	return 0;
}

// rumus heron itu kan
// sqrt(s(s-a)(s-b)(s-c))

// s itu keliling / 2

// sqrt itu akan bisa kalo

// a+b+c/2

// n*m/k if itu /2 * /2 /2

// 2 * 2 * 2

// s = 3

// 2^4

// 2^2

// 1 * 1 * 1

// luas segitiga berapa per 4

// 1/4 bs ga si?

