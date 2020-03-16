/*
 * Author: apikdech
 * Time: 14:14:36 21-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1005;
pair<int, int> a[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a+1, a+1+n);
	reverse(a+1, a+1+n);
	for (int i = 0; i < n; i++) {
		sum += i*a[i+1].first + 1;
	}
	cout << sum << "\n";
	for (int i = 1; i <= n; i++) {
		cout << a[i].second << " \n"[i==n];
	}
	return 0;
}
