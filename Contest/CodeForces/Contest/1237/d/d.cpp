/*
 * Author: apikdech
 * Time: 23:16:31 16-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 4e5 + 5;

int mx[N][25], mn[N][25]; 
int a[N];
  
int lg[N+1];

void pre() {
	lg[1] = 0;
	for (int i = 2; i <= N; i++) lg[i] = lg[i/2] + 1;	
}

int query(int l, int r, int val) {
	int j = lg[r - l + 1];
	if (val) return max(mx[l][j], mx[r - (1 << j) + 1][j]);
	return min(mn[l][j], mn[r - (1 << j) + 1][j]);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	pre();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] *= 2;
		a[n+i] = a[i];
		a[2*n + i] = a[i];
	}
	n *= 3;
	for (int i = 0; i < n; i++) {
		mx[i][0] = mn[i][0] = a[i];
	}
	for (int j = 1; j < 25; j++) {
		for (int i = 0; i + (1 << j) <= n; i++) {
			mx[i][j] = max(mx[i][j-1], mx[i + (1 << (j - 1))][j - 1]);
			mn[i][j] = min(mn[i][j-1], mn[i + (1 << (j - 1))][j - 1]);
		}
	}
	for (int i = 0; i < n/3; i++) {
		int ans = 0;
		int l = 0, r = n - l - 1, m;
		// cout << i << ":\n";
		while(l <= r) {
			m = (l + r) >> 1;
			cout << i << " " << i+m << " ";
			int tmin = query(i, i+m, 0);
			int tmax = query(i, i+m, 1);
			cout << tmin << " " << tmax << "\n";
			if (a[i+m+1] * 2 >= tmax) l = m+1, ans = m;
			else r = m - 1, ans = m;
		}
		// cout << ans << " ";
	}
	return 0;
}
