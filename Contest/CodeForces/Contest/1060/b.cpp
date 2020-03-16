#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, sub, a, b, aa = 0, bb = 0;
	cin >> n;
	sub = log10(n);
	if (sub == 0) {
		a = n-1, b = 1;
		return cout << a + b << "\n", 0;
	}
	sub = pow(10, sub);
	sub--;
	a = sub, b = n-sub;
	while (a > 0) {
		aa += a % 10;
		a /= 10;
	}
	while (b > 0) {
		bb += b % 10;
		b /= 10;
	}
	cout << aa + bb << "\n";
	return 0;
}

// angka kurang 10^n - 1