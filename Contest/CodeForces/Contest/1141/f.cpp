#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 1505;
int a[N], sum[N], mx = 0;
unordered_map<int, vector<pair<int, int>>> m;
vector<pair<int, int>> ans;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = a[i] + sum[i-1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			m[sum[j]-sum[i-1]].push_back({j, i});
		}
	}
	for (auto it : m) {
		sort(it.second.begin(), it.second.end());
		int cnt = 1, last = it.second[0].first;
		vector<pair<int, int>> tmp;
		tmp.push_back({it.second[0].first, it.second[0].second});
		for (int i = 1; i < it.second.size(); i++) {
			if (it.second[i].second > last) {
				cnt++;
				last = it.second[i].first;
				tmp.push_back({it.second[i].first, it.second[i].second});
			}
		}
		if (cnt > mx) {
			ans = tmp;
			mx = cnt;
		}
	}
	cout << ans.size() << "\n";
	for (auto it : ans) cout << it.second << " " << it.first << "\n";
	return 0;
}