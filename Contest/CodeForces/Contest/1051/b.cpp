#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ll l, r;
	cin >> l >> r;
	cout << "YES\n";
	for (ll i = l; i <= r; i += 2) 
		cout << i << " " << i+1 << "\n";
	return 0;
}