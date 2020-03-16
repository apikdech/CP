/*
 * Author: apikdech
 * Time: 13:14:47 02-06-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 3e5 + 5;
vector<pair<int, pair<int, int>>> a, b;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		if (x < y) a.push_back({y, {x, i}});
		else b.push_back({y, {x, i}});
	}
	sort(a.rbegin(), a.rend());
	sort(b.begin(), b.end());
	int last = 1e9;
	vector<int> tmp, ans;
	for (auto it : a) {
		if (last > it.second.first) {
			last = it.first;
			tmp.push_back(it.second.second);
		}
	}
	ans = tmp;
	tmp.clear();
	last = 0;
	for (auto it : b) {
		if (last < it.second.first) {
			last = it.first;
			tmp.push_back(it.second.second);
		}
	}
	if (ans.size() < tmp.size()) ans = tmp;
	cout << ans.size() << "\n";
	for (auto it : ans) cout << it << " ";
	return 0;
}
