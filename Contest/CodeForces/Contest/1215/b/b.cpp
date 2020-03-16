/*
 * Author: apikdech
 * Time: 21:38:06 15-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
ll a = 0, b = 0, pos = 0, neg = 0, cnt = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (cnt & 1) b++;
		else a++;
		if (x < 0) cnt++;
		if (cnt & 1) pos += b, neg += a;
		else pos += a, neg += b;
	}
	cout << neg << " " << pos << "\n";
	return 0;
}
