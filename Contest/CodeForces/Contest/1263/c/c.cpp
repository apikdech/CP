/**
 * author:  apikdech
 * created: 29.11.2019 22:09:06
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		vector<int> ans;
		ans.push_back(0);
		ans.push_back(1);
		cin >> n;
		for (int i = 1; i * i <= n; i++) {
			ans.push_back(n/i);
			ans.push_back(i);
		}
		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		cout << ans.size() << "\n";
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " \n"[i + 1 == (int)ans.size()];
		}
	}
	return 0;
}
