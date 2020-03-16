/**
 * author:  apikdech
 * created: 24.11.2019 18:30:02
**/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int MOD = 1000000007, N = 2e5 + 5;
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).

ordered_set X;
vector<pair<int, int>> num;
int ans[N];
vector<tuple<int, int, int>> query;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		num.push_back({x, i});
	}
	sort(num.begin(), num.end(), [&](pair<int, int> a, pair<int, int> b) {
		return a.first > b.first || (a.first == b.first && a.second < b.second);
	});
	int m, ptr = 0;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int k, pos;
		cin >> k >> pos;
		query.push_back({k, pos, i});
	}
	sort(query.begin(), query.end());
	for (int i = 0; i < m; i++) {
		auto [len, pos, idx] = query[i];
		while(X.size() < len) {
			X.insert({num[ptr].second, num[ptr].first});
			ptr++;
		}
		ans[idx] = X.find_by_order(pos-1)->second;
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}
