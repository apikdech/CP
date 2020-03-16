#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 2e5 + 5;
set<pair<int, int>> s, pos;
int ans[N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n, k, x, t = 1;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		s.insert({-x, i});
		pos.insert({i, -x});
	}
	while(!s.empty()) {
		auto xx = s.begin();
		int fi = xx->first, se = xx->second;
		s.erase(xx);
		auto id = pos.find({se, fi});
		for (int i = 0; i < k; i++) {
			auto it = next(id);
			if (it == pos.end()) break;
			ans[it->first] = t;
			s.erase({it->second, it->first});
			pos.erase(it);
		}
		for (int i = 0; i < k; i++) {
			if (id == pos.begin()) break;
			auto it = prev(id);
			ans[it->first] = t;
			s.erase({it->second, it->first});
			pos.erase(it);
		}
		ans[id->first] = t;
		pos.erase(id);
		if (t == 1) t = 2;
		else t = 1;
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i];
	}
	cout << "\n";
	return 0;
}