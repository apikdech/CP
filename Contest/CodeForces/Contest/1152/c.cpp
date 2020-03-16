#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

ll lcm(ll x, ll y) {
	return (x/__gcd(x,y) * y);
}

int main() {
	ll a, b, x, k, ans, t, res = 0;
	vector<ll> v;
	cin >> a >> b;
	ans = lcm(a, b);
	x = abs(a - b);
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			v.push_back((ll)i);
			if (x/(ll)i != i) v.push_back(x/(ll)i);
		}
	}
	if (x != 0)v.push_back(x);
	for (int i = 0; i < (int)v.size(); i++) {
		k = v[i] - a % v[i];
		t = lcm(a + k, b + k);
		if (t < ans) ans = t, res = k;
	}
	cout << res << "\n";
	return 0;
}