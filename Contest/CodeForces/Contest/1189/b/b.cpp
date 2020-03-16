/*
 * Author: apikdech
 * Time: 22:22:19 05-07-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
int a[N], ans[N];
deque<int> q;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, ok = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	reverse(a, a+n);
	for (int i = 0; i < n; i++) {
		if (i & 1) q.push_back(a[i]);
		else q.push_front(a[i]);
	}
	for (int i = 0; i < n; i++) {
		ans[i] = q.front();
		q.pop_front();
	}
	for (int i = 0; i < n; i++) {
		if (i == 0 && ans[i] >= ans[i+1] + ans[n-1]) ok = 0;
		else if (i == n-1 && ans[i] >= ans[i-1] + ans[0]) ok = 0;
		else if (i > 0 && i < n-1 && ans[i] >= ans[i+1] + ans[i-1]) ok = 0;
		// if (!ok) cout << i << "\n";
	}
	if (!ok) cout << "NO\n";
	else {
		cout << "YES\n";
		for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n-1];
	}
	return 0;
}
