/**
 * author:  apikdech
 * created: 12.12.2019 21:08:43
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;

int a[N];
vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int fi = 0, la = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < a[i+1]) la = i+1;
		else {
			v.push_back({fi, la});
			fi = la = i+1;
		}
	}
	if (fi != la) v.push_back({fi, la});
	for (auto it : v) {
		// cout << it.first << " " << it.second << "\n";
		ans = max(ans, it.second - it.first + 1);
	}
	for (int i = 0; i < (int)v.size()-1; i++) {
		int l1 = v[i].first;
		int r1 = v[i].second;
		int l2 = v[i+1].first;
		int r2 = v[i+1].second;
		if (r1 - l1 > 0 && a[r1 - 1] < a[l2]) ans = max(ans, r1 - l1 + r2 - l2 + 1);
		if (r2 - l2 > 0 && a[r1] < a[l2 + 1]) ans = max(ans, r1 - l1 + 1 + r2 - l2);
	}
	cout << ans << "\n";
	return 0;
}
