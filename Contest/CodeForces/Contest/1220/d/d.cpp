/*
 * Author: apikdech
 * Time: 12:18:12 19-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;
ll a[N], mx = 0;
vector<ll> ans;
map<ll, int> cnt;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[(a[i]&(-a[i]))]++;
	}
	for (auto it : cnt) {
		if (it.second > cnt[mx]) mx = it.first;
	}
	for (int i = 0; i < n; i++) {
		if (mx != (a[i] & (-a[i]))) ans.push_back(a[i]);
	}
	cout << ans.size() << "\n";
	for (auto it : ans) cout << it << " ";
	return 0;
}
