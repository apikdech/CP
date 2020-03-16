/*
 * Author: apikdech
 * Time: 21:44:22 24-07-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;
int a[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		int k, n, odd = 0, ok = 1;
		vector<int> o;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] & 1) {
				odd++;
				o.push_back(i+1);
			}
		}
		if (odd < k || (odd - k) % 2 != 0) ok = 0;
		else ok = 1;
		if (!ok) cout << "NO\n";
		else {
			cout << "YES\n";
			for (int i = 0; i < k-1; i++) {
				cout << o[i] << " ";
			}
			cout << n << "\n";
		}
	}
	return 0;
}
