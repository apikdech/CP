#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int n, m, k, ans = 0;
	cin >> n >> m >> k;
	while(k--) {
		ans += (n*m) - (n-2)*(m-2);
		n -= 4;
		m -= 4;
	}
	cout << ans << "\n";
	return 0;
}