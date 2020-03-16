/*
 * Author: apikdech
 * Time: 23:23:20 22-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll x = 1;
	map<ll, bool> v;
	for (int i = 0; i < 14; i++) {
		x = 2LL << i;
		v[x] = 1;
		ll tmp = 1;
		while(true) {
			if (v.count(x-tmp) || x-tmp < 0) break;
			v[x-tmp] = 1;
			tmp <<= 1;
		}
	}
	cout << v.size() << "\n";
	for (auto it : v) cout << it.first << " ";
	return 0;
}
