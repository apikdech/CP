/**
 * author:  apikdech
 * created: 16.11.2019 21:45:51
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
int a[N], res = 0;
set<int> s, vis;
vector<int> ans;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, cnt = 0, ok = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > 0 && vis.count(a[i])) {
			if (!s.empty()) ok = 0;
			else {
				vis.clear();
				if (cnt != 0) ans.push_back(cnt);
				cnt = 1;
				s.insert(a[i]);
			}
		}
		else if (a[i] > 0 && !s.count(a[i])) {
			s.insert(a[i]);
			cnt++;
		}
		else if (a[i] < 0 && s.count(-a[i])) {
			s.erase(-a[i]);
			vis.insert(-a[i]);
			cnt++;
			if (s.empty()) {
				ans.push_back(cnt);
				vis.clear();
				cnt = 0;
			}
		}
		else if (a[i] < 0 && !s.count(-a[i])) ok = 0;
		else if (a[i] > 0 && s.count(a[i])) ok = 0;

	}
	if (!s.empty() || !ok) cout << "-1\n";
	else {
		if (cnt != 0) ans.push_back(cnt);
		cout << ans.size() << "\n";
		for (int it : ans) cout << it << " ";
	}
	return 0;
}
