#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int q;
	cin >> q;
	while(q--) {
		ll n, a, b;
		cin >> n >> a >> b;
		if (a < b/2.0) cout << n*a << "\n";
		else if (n & 1) cout << n/2 * b + a << "\n";
		else cout << n/2 * b << "\n";
	}
	return 0;
}