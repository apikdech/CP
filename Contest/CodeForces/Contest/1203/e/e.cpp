/*
 * Author: apikdech
 * Time: 22:14:53 13-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;
int cnt[N], ans[N];
vector<int> v;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
		cnt[x]++;
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (auto it : v) {
		if (cnt[it] >= 3) {
			ans[it-1]++, ans[it+1]++;
			if (cnt[it-1]) ans[it-2]++;
		}
		else if (cnt[it] >= 2) {
			if (cnt[it+1] || ans[it+1]) ans[it-1]++;
			else ans[it+1]++;
		} else if (ans[it]) ans[it+1]++;
		ans[it]++;
	}
	for (int i = 1; i < N; i++) {
		// if (i <= 6) cout << ans[i] << " ";
		if (ans[i]) res++;
	}
	cout << res << "\n";
	return 0;
}
