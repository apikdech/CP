#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 2e5 + 5;
ll cnt[N], mx = 0, a[N], ans, x, n;
vector<pair<int, pair<int, int>>> v;
queue<int> q;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
		if (cnt[a[i]] > mx) mx = cnt[a[i]], ans = a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == ans && a[i-1] != ans || a[i] == ans && a[i+1] != ans) q.push(i);
	}
	while(!q.empty()) {
		x = q.front();
		q.pop();
		if (a[x] > a[x-1] && x-1 > 0) {
			v.push_back({1, {x-1, x}});
			a[x-1] = a[x];
			q.push(x-1);
		} else if (a[x] < a[x-1] && x-1 > 0) {
			v.push_back({2, {x-1, x}});
			a[x-1] = a[x];
			q.push(x-1);
		} if (a[x] > a[x+1] && x+1 <= n) {
			v.push_back({1, {x+1, x}});
			a[x+1] = a[x];
			q.push(x+1);
		} else if (a[x] < a[x+1] && x+1 <= n) {
			v.push_back({2, {x+1, x}});
			a[x+1] = a[x];
			q.push(x+1);
		}
	}
	cout << v.size() << "\n";
	for (auto i : v) cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
	return 0;
}