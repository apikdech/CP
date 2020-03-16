/*
 * Author: apikdech
 * Time: 21:35:21 09-06-2019
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
		ll n, ok = 1, step = 0;
		cin >> n;
		while(n != 1) {
			if (n % 2 == 0) n /= 2;
			else if (n % 3 == 0) n = 2*n/3;
			else if (n % 5 == 0) n = 4*n/5;
			else {
				ok = 0;
				break;
			}
			step++;
		}
		if (!ok || n != 1) cout << "-1\n";
		else cout << step << "\n";
	}
	return 0;
}
