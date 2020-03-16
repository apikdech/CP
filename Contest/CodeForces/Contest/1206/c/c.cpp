/*
 * Author: apikdech
 * Time: 21:38:48 18-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	if (n % 2 == 0) cout << "NO\n";
	else {
		cout << "YES\n";
		int cur = 2*n, step = 2*n-1;
		for (int i = 0; i < n; i++) {
			cout << cur << " ";
			if (i & 1) cur += step;
			else cur -= step;
			step -= 2;
		}
		cur = 2*n-1, step = 2*n-3;
		for (int i = 0; i < n; i++) {
			cout << cur << " \n"[i==n-1];
			if (i & 1) cur += step;
			else cur -= step;
			step -= 2;
		}
	}
	return 0;
}
