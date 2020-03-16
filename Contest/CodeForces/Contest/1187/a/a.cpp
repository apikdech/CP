/*
 * Author: apikdech
 * Time: 21:52:12 30-06-2019
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
		ll n, s, t;
		cin >> n >> s >> t;
		cout << n - min(s, t) + 1 << "\n";
	}
	return 0;
}
