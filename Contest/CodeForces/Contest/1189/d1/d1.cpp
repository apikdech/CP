/*
 * Author: apikdech
 * Time: 23:55:53 05-07-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
int n, deg[N], ok = 1;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		deg[x]++;
		deg[y]++;
	}
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 2) ok = 0;
	}
	if (n < 3) cout << "YES\n";
	else if (!ok) cout << "NO\n";
	else cout << "YES\n";
	return 0;
}
