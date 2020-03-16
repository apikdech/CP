/*
 * Author: apikdech
 * Time: 20:24:55 30-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e3 + 5;
int a[N][N];

ll powmod(ll a,ll b) {ll res=1; assert(b>=0); for(;b;b>>=1){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;}return res%MOD;}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	memset(a, -1, sizeof a);
	int r, c, ok = 1, ans = 0;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < x; j++) {
			a[i][j] = 1;
		}
		a[i][x] = 0;
	}
	for (int i = 0; i < c; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < x; j++) {
			if (a[j][i] == 0) ok = 0;
			a[j][i] = 1;
		}
		if (a[x][i] == 1) ok = 0;
		a[x][i] = 0;
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			// cout << a[i][j] << " ";
			if (a[i][j] == -1) ans++;
		}
		// cout << "\n";
	}
	ans = powmod(2, ans);
	if (!ok) cout << "0\n";
	else cout << ans << "\n";
	return 0;
}
