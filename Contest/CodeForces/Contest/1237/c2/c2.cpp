/*
 * Author: apikdech
 * Time: 22:45:11 16-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;

bool v[N];

struct point {
	ll x, y, z;
	int idx;
};
point a[N];

bool cmp(point p, point q) {
	return p.x < q.x || (p.x == q.x && p.y < q.y) || (p.x == q.x && p.y == q.y && p.z < q.z);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
		a[i].idx = i+1;
	}
	sort(a, a+n, cmp);

	for (int i = 0; i < n; i++) {
		if (v[i] || v[i+1]) continue;
		if (a[i].x != a[i+1].x || a[i].y != a[i+1].y) continue;
		if (a[i].idx == 0 || a[i+1].idx == 0) continue;
		cout << a[i].idx << " " << a[i+1].idx << "\n";
		v[i] = v[i+1] = 1;
	}
	for (int i = 0, j = 0; i < n; i++) {
		if (v[i]) continue;
		j = i+1;
		while(j < n && v[j]) j++;
		if (j == n) break;
		if (a[i].x != a[j].x) continue;
		if (a[i].idx == 0 || a[j].idx == 0) continue;
		cout << a[i].idx << " " << a[j].idx << "\n";
		v[i] = v[j] = 1;
	}
	for (int i = 0, j = 0; i < n; i++) {
		if (v[i]) continue;
		j = i+1;
		while(j < n && v[j]) j++;
		if (j == n) break;
		if (a[i].idx == 0 || a[j].idx == 0) continue;
		cout << a[i].idx << " " << a[j].idx << "\n";
		v[i] = v[j] = 1;

	}
	return 0;
}
