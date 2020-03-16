/*
 * Author: apikdech
 * Time: 10:36:54 07-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
pair<ll, int> p[N];
ll x, y, a, b, k, lcm;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		int n, cnt = 0, ok = 0, ans = 0;
		ll sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> p[i].first;
			p[i].second = i+1;
		}
		sort(p, p+n, [](pair<ll, int> a, pair<ll, int> b) {
			return a.first > b.first || ((a.first == b.first) && a.second < b.second);
		});
		cin >> x >> a;
		cin >> y >> b;
		cin >> k;
		if (x < y) {
			swap(x, y);
			swap(a, b);
		}
		lcm = a*b/__gcd(a, b);
		lcm = n/lcm;
		a = n/a - lcm;
		b = n/b - lcm;
		
	}
	return 0;
}
