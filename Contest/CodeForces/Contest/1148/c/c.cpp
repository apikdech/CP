/*
 * Author: apikdech
 * Time: 22:59:45 01-06-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 3e5 + 5;
int a[N], pos[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	vector<pair<int, int>> ans;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == i) continue;
		int &x = pos[i], &y = pos[a[i]];
		if (abs(pos[a[i]] - pos[i]) >= n/2) {
			ans.push_back({pos[a[i]], pos[i]});
			swap(a[i], a[pos[i]]);
			swap(x, y);
		} else if (pos[a[i]] <= n/2 && pos[i] <= n/2) {
			ans.push_back({pos[i], n});
			ans.push_back({pos[a[i]], n});
			ans.push_back({pos[i], n});
			swap(a[i], a[pos[i]]);
			swap(x, y);
		} else if (pos[a[i]] > n/2 && pos[i] > n/2) {
			ans.push_back({pos[i], 1});
			ans.push_back({pos[a[i]], 1});
			ans.push_back({pos[i], 1});
			swap(a[i], a[pos[i]]);
			swap(x, y);
		} else {
			int p = pos[i], q = pos[a[i]];
			if (p > q) swap(p, q);
			ans.push_back({p, n});
			ans.push_back({q, 1});
			ans.push_back({1, n});
			ans.push_back({p, n});
			ans.push_back({q, 1});
			swap(a[i], a[pos[i]]);
			swap(x, y);
		}
	}
	cout << ans.size() << "\n";
	for (auto it : ans) {
		cout << it.first << " " << it.second << "\n";
	}
	return 0;
}
