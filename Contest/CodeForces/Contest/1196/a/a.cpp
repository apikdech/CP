/*
 * Author: apikdech
 * Time: 21:38:09 24-07-2019
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
		ll a, b, c;
		cin >> a >> b >> c;
		cout << (a + b + c)/2 << "\n";
	}
	return 0;
}
