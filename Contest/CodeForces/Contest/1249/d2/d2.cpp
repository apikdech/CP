/*
 * Author: apikdech
 * Time: 22:34:54 22-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 4e5 + 5;
pair<int, int> point[N];
pair<int, pair<int, int>> loc[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> point[i].first >> point[i].second;
		loc[i << 1] = {point[i].first, {0, i}};
		loc[i << 1 | 1] = {point[i].second, {1, i}};
	}
	sort(loc, loc + 2*n);
	set<pair<int, int>> s;
	vector<int> ans;
	for (int i = 0; i < 2*n; i++) {
		int idx = loc[i].second.second;
		if (loc[i].second.first) s.erase({-point[idx].second, idx});
		else {
			s.insert({-point[idx].second, idx});
			if (s.size() > k) {
				ans.push_back((*s.begin()).second + 1);
				s.erase(*s.begin());
			}
		}
	}
	cout << ans.size() << "\n";
	for (int it : ans) cout << it << " ";
	return 0;
}
