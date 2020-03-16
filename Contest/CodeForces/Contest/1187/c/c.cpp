/*
 * Author: apikdech
 * Time: 22:12:01 30-06-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e3 + 5, INF = 1e9;
int t[N], l[N], r[N], a[N], mn = 0;
bool up[N];

int main() {
	int n, m, ok = 1;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> t[i] >> l[i] >> r[i];
		l[i]--, r[i]--;
		if (t[i]) for (int j = l[i]; j < r[i]; j++) up[j] = 1;
	}
	for (int i = 0; i < m; i++) {
		if (!t[i]) {
			ok = 0;
			for (int j = l[i]; j < r[i]; j++) {
				if (!up[j]) ok = 1;
			}
		}
		if (!ok) return cout << "NO\n", 0;
	}
	a[0] = 0;
	for (int i = 0; i <= n; i++) {
		if (up[i]) a[i+1] = a[i] + 1;
		else a[i+1] = a[i] - 1;
		mn = min(mn, a[i+1]);
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		a[i] += 1 - mn;
		cout << a[i] << " \n"[i == n-1];
	}
	return 0;
}