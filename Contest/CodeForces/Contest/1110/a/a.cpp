#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int a, b, k, ans = 0;
	cin >> b >> k;
	b &= 1;
	for (int i = 0; i < k; i++) {
		cin >> a;
		a &= 1;
		if (i != k-1) ans += a*b;
		else ans += a;
		ans %= 2;
	}
	if (!ans) cout << "even\n";
	else cout << "odd\n";
	return 0;
}