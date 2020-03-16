/*
 * Author: apikdech
 * Time: 21:44:29 09-06-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 5e5 + 5;
int a[N], x[] = {4, 8, 15, 16, 23, 42};
queue<int> v[50], q;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		v[a[i]].push(i);
		if (a[i] == 4) q.push(i);
	}
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 1; i < 6; i++) {
			if (v[x[i]].empty()) break;
			int xx = v[x[i]].front();
			v[x[i]].pop();
			while(u > xx) {
				if (v[x[i]].empty()) break;
				xx = v[x[i]].front();
				v[x[i]].pop();
			}
			if (u < xx) u = xx;
		}
		if (a[u] == 42) cnt++;
	}
	// cerr << cnt << "\n";
	cout << n - cnt*6 << "\n";
	return 0;
}
