/*
 * Author: apikdech
 * Time: 05:58:43 27-05-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, a, b;
	vector<pair<int, int>> v;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v.push_back({a, b});
	}
	vector<int> val = {v[0].first, v[0].second};
	for (int x : val) {
		vector<int> cnt(n+1);
		int all = 0;
		for (auto c : v) if (c.first != x && c.second != x) cnt[c.first]++, cnt[c.second]++, all++;
		if (*max_element(cnt.begin(), cnt.end()) == all) return cout << "YES\n", 0;
		// cerr << (*max_element(cnt.begin(), cnt.end())) << " " << all << "\n";
	}
	cout << "NO\n";
	return 0;
}
