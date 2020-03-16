#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	if (m % n != 0 || (m/n % 2 != 0 && m/n % 3 != 0 && m != n)) cout << "-1\n";
	else {
		m /= n;
		while(m % 2 == 0) {
			m /= 2;
			ans++;
		}
		while(m % 3 == 0) {
			m /= 3;
			ans++;
		}
		if (m == 1) cout << ans << "\n";
		else cout << "-1\n";
	}
	return 0;
}

//2*n or 3*n or 6*n