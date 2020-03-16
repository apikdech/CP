/*
 * Author: apikdech
 * Time: 23:44:20 14-07-2019
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
		int k, n;
		cin >> n >> k;
		if (n == k) cout << "Alice\n";
		else if (k % 4 != 0 && n % 4 == 0) cout << "Bob\n";
		else if (n - k % 4 == 0 && k % 4 != 0) cout << "Bob\n";
		else cout << "Alice\n";
	}
	return 0;
}
