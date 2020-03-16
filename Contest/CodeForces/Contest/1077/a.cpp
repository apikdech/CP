#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int t;
	cin >> t;
	while(t--) {
		ll a, b, k, ans;
		cin >> a >> b >> k;
		ans = (k+1)/2 * a - k/2 * b;
		cout << ans << "\n";
	}
	return 0;
}