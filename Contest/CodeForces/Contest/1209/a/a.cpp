/*
 * Author: apikdech
 * Time: 20:05:16 14-09-2019
 * Last Modified: 20:10:37 14-09-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 105;
int a[N], vis[N];
vector<int> ans;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		ans.push_back(a[i]);
		for (int j = i + 1; j < n; j++) {
			if (a[j] % a[i] == 0) vis[j] = 1;
		}
	}
	cout << ans.size() << "\n";
	// cerr << "time = " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << " ms\n";
	return 0;
}