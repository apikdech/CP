/*
 * Author: apikdech
 * Time: 22:29:09 03-06-2019
 * Last Modified: 23:09:21 03-06-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e4;
ll a[N], sum = 0, x = 0, y = 0, n, idx = 0, ok = 0;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 0; i < 2*n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a+2*n);
	for (int i = 0; i < n; i++) x += a[i];
	if (2*x == sum) return cout << "-1\n", 0;
	for (int i = 0; i < 2*n; i++) {
		cout << a[i] << " \n"[i == 2*n-1];
	}
	return 0;
}