/**
 * author:  apikdech
 * created: 21.12.2019 18:10:18
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

bool prime(ll x) {
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll n, a = 4, b;
	cin >> n;
	b = n + a;
	while(prime(b)) b += 2, a += 2;
	cout << b << " " << a << "\n";
	return 0;
}
