/*
 * Author: apikdech
 * Time: 20:58:02 18-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1005;
int a[N], b[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		b[x]++;
	}
	for (int i = 1; i <= 200; i++) {
		for (int j = 1; j <= 200; j++) {
			if (a[i] && b[j] && !a[i+j] && !b[i+j]) return cout << i << " " << j << "\n", 0;
		}
	}
	return 0;
}
