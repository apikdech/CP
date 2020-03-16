/*
 * Author: apikdech
 * Time: 21:37:44 03-06-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
int a[N], odd = 0, even = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] & 1) odd++;
		else even++;
	}
	if (odd && even) sort(a, a+n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " \n"[i == n-1];
	}
	return 0;
}
