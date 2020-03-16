/*
 * Author: apikdech
 * Time: 22:45:02 20-07-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int a[105];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, sum = 0, tsum = 0;
	vector<int> ans;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	ans.push_back(0);
	tsum = a[0];
	for (int i = 1; i < n; i++) {
		if (a[0] >= 2*a[i]) {
			tsum += a[i];
			ans.push_back(i);
		}
	}
	if (tsum > sum/2) {
		cout << ans.size() << "\n";
		for (auto it : ans) cout << it+1 << " ";
	}
	else cout << "0\n";
	return 0;
}
