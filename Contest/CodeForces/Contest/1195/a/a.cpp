/*
 * Author: apikdech
 * Time: 21:35:28 17-07-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e3 + 5;
map<int, int> a;

int main() {
	int n, k, ans = 0, cnt = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x]++;
	}
	for (auto it : a) {
		cnt += it.second % 2;
		ans += it.second / 2 * 2;
	}
	ans += (cnt + 1) / 2;
	cout << ans << "\n";
	return 0;
}