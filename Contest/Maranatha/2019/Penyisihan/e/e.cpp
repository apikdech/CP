/*
 * Author: apikdech
 * Time: 09:54:02 07-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 25;
int a[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, sum = 0, ok = 1;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a+n);
		reverse(a, a+n);
		for (int i = 1; i < n; i++) {
			sum += a[i];
		}
		if (a[0] > sum) ok = 0;
		if (!ok) cout << "false\n";
		else cout << "true\n";
	}
	return 0;
}
