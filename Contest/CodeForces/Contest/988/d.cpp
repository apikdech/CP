#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 2e5 + 5;
// unordered_map<int, bool> m;
unordered_set<int> m;
vector<int> ans;
int a[N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, ok = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m.insert(a[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 30; j++) {
			if (m.count(a[i] + (1 << j)) && m.count(a[i] - (1 << j))) {
				ok = 2;
				ans = {a[i], a[i] + (1 << j), a[i] - (1 << j)};
				break;
			} else if (!ok && (m.count(a[i] + (1 << j)) || m.count(a[i] - (1 << j)))) {
				ok = 1;
				ans = {a[i], m.count(a[i] + (1 << j)) ? a[i] + (1 << j) : a[i] - (1 << j)};
			}
		} if (ok == 2) break;
	}
	if (ans.size() == 0) return cout << "1\n" << a[0] << "\n", 0;
	cout << ans.size() << "\n";
	for (auto i : ans) cout << i << " ";
	return 0;
}