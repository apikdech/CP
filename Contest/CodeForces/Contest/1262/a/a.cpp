/**
 * author:  apikdech
 * created: 24.11.2019 15:11:14
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, mx = -1, mn = 1e9 + 5;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			mx = max(mx, a);
			mn = min(mn, b);
		}
		cout << max(mx - mn, 0) << "\n";
	}
	return 0;
}
