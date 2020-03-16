/*
 * Author: apikdech
 * Time: 14:59:46 11-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
ll sum = 0, tsum = 0, mx = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	while(n--) {
		ll x;
		cin >> x;
		mx = max(mx, x);
		sum += x;
	}	
	tsum = sum - mx;
	if (sum & 1 || tsum < mx) cout << "NO\n";
	else cout << "YES\n";
	return 0;
}
