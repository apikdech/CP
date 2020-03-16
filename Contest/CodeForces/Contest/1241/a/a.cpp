/*
 * Author: apikdech
 * Time: 10:18:13 07-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		int n;
		cin >> n;
		if (n < 4) cout << 4 - n << "\n";
		else if (n & 1) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	return 0;
}
