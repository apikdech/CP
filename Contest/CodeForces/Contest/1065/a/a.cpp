#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int t;
	cin >> t;
	while(t--) {
		ll s, a, b, c, bonus, ans = 0;
		cin >> s >> a >> b >> c;
		s /= c;
		ans += s + s/a*b;
		cout << ans << "\n";
	}
	return 0;
}