/**
 * author:  apikdech
 * created: 07.11.2019 09:15:03
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll n, g = 0;
	vector<ll> v;
	cin >> n;
	if (n == 1) return cout << "1\n", 0;
	for (ll i = 2; i * i <= n; i++) {
		int ok = 0;
		while(n % i == 0) n /= i, ok = 1;
		if (ok) v.push_back(i);
	}
	if (n > 1) v.push_back(n);
	for (auto it : v) g = __gcd(g, it);
	cout << g << "\n";
	return 0;
}
