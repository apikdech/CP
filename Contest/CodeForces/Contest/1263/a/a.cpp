/**
 * author:  apikdech
 * created: 29.11.2019 21:43:43
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
		ll x[3];
		for (int i = 0; i < 3; i++) cin >> x[i];
		sort(x, x+3);
		cout << min(x[0] + x[1], (x[0] + x[1] + x[2])/2) << "\n";
	}
	return 0;
}
