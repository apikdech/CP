/*
 * Author: apikdech
 * Time: 14:45:37 25-05-2019
 * Last Modified: 14:58:01 25-05-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;
int a[N], l[N], r[N], pos[N];
vector<pair<int, int>> v;

int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	v.push_back({n+1, -1});
	for (int i = 0; i < n; i++) {
		while(a[i] > v.back().first) v.pop_back();
		l[i] = v.back().second + 1;
		v.push_back({a[i], i});
	}
	v.clear();
	v.push_back({n+1, n});
	for (int i = n-1; i >= 0; i--) {
		while(a[i] > v.back().first) v.pop_back();
		r[i] = v.back().second - 1;
		v.push_back({a[i], i});
	}
	for (int i = 0; i < n; i++) {
		if (i - l[i] < r[i] - i) 
			for (int j = l[i]; j < i; j++) {
				int x = a[i] - a[j];
				if (x >= 1 && x <= n && pos[x] > i && pos[x] <= r[i]) ans++;
			}
		else 
			for (int j = i; j <= r[i]; j++) {
				int x = a[i] - a[j];
				if (x >= 1 && x <= n && pos[x] < i && pos[x] >= l[i]) ans++;
			}
	}
	cout << ans << "\n";
	return 0;
}