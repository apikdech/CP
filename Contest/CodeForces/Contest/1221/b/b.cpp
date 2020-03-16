/*
 * Author: apikdech
 * Time: 22:56:03 20-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 105;
char loc[N][N];
int dx[] = {2, 1, 2, 1, -2, -1, -2, -1};
int dy[] = {1, 2, -1, -2, 1, 2, -1, -2};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, ok = 1;
	cin >> n;
	memset(loc, 0, sizeof loc);
	for (int i = 1; i <= n; i++) {
		if (i & 1) ok = 1;
		else ok = 0;
		for (int j = 1; j <= n; j++) {
			loc[i][j] = (ok ? 'W' : 'B');
			ok ^= 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << loc[i][j];
		}
		cout << "\n";
	}
	return 0;
}
