/*
 * Author: apikdech
 * Time: 17:14:07 28-06-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string a, b;
	cin >> a >> b;
	int n = a.length(), m = b.length(), ans = 0;
	for (int i = 0; i <= n - m; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			if (a[i+j] != b[j]) cnt++;
		}
		// cerr << cnt << " ";
		if (cnt % 2 == 0) ans++;
	}
	cout << ans << "\n";
	return 0;
}
