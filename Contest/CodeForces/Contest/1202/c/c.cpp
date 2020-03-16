/*
 * Author: apikdech
 * Time: 23:10:13 07-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		map<int, int> cntx, cnty;
		string s;
		ll a = 0, b = 0, mx = 0, my = 0, mnx = 1e6, mny = 1e6, ans = 0;
		cin >> s;
		for (char c : s) {
			if (c == 'W') a++;
			else if (c == 'S') a--;
			else if (c == 'D') b++;
			else b--;
			cntx[a]++;
			cnty[b]++;
			mx = max(mx, a);
			my = max(my, b);
			mnx = min(mnx, a);
			mny = min(mny, b);
		}
		if (cntx[mx] < 2 && cnty[my] < 2) {
			if (mnx < 0) mx += -mnx;
			if (mny < 0) my += -mny;
			ans = min({mx*my, (mx-1)*my, (my-1)*mx});
		}
		if (cntx[mx] < 2) {
			if (mnx < 0) mx += -mnx;
			ans = min(mx*my, (mx-1)*my);
		}
		if (cnty[my] < 2) {
			if (mny < 0) my += -mny;
			ans = min(mx*my, (my-1)*mx);
		} else {
			if (mnx < 0) mx += -mnx;
			if (mny < 0) my += -mny;
			ans = mx*my;
		}
		cout << ans << "\n";
	}
	return 0;
}
