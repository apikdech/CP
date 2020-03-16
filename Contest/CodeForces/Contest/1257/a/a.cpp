/**
 * author:  apikdech
 * created: 13.11.2019 21:39:27
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
		int n, x, a, b;
		cin >> n >> x >> a >> b;
		cout << min(n-1, abs(a-b) + x) << "\n";
	}
	return 0;
}
