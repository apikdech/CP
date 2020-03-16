/**
 * author:  apikdech
 * created: 16.11.2019 20:36:55
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
		int x, y;
		cin >> x >> y;
		if (x == 1 && y == 1) cout << "YES\n";
		else if ((x == 2 || x == 3) && y <= 3) cout << "YES\n";
		else if (x > 3) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
