/*
 * Author: apikdech
 * Time: 00:02:31 18-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
set<int> row[N], col[N], vrow, vcol;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll n, m, k, sum = 0, X = 1, Y = 1, dir = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		row[x].insert(y);
		col[y].insert(x);
	}
	ll lx = 1, ly = 1, rx = n, ry = m;
	while(true) {
		ll tmp = sum, inc = 0;
		if (dir == 0) {
			auto idx = upper_bound();
			auto t = lower_bound(vrow.begin(), vrow.end(), pos_x);
			if (pos_x != *t && t != vrow.end() && (idx == col[pos_y].end() || *t < *idx)) inc = *t - pos_x, pos_x = *t - 1;
			else if (idx == col[pos_y].end()) inc = m - pos_x + 1, pos_x = m;
			else inc = *idx - pos_x, pos_x = *idx - 1;
			sum += inc;
			vcol.push_back(pos_y);
			sort(vcol.begin(), vcol.end());
		} else if (dir == 1) {
			// auto idx = lower_bound(row[pos_x].begin(), row[pos_x].end(), pos_y);
			// auto t = lower_bound(vcol.begin(), vcol.end(), pos_y);
			// if (pos_y != *t && t != vcol.end() && (idx == row[pos_x].end() || *t < *idx)) inc = *t - pos_y, pos_y = *t - 1;
			// else if (idx == row[pos_x].end()) inc = n - pos_y + 1, pos_y = n;
			// else inc = *idx - pos_y, pos_y = *idx - 1;
			// sum += inc;
			// vrow.push_back(pos_x);
			// sort(vrow.begin(), vrow.end());
		} else if (dir == 2) {
			// auto idx = lower_bound(col[pos_y].begin(), col[pos_y].end(), pos_x);
			// auto t = lower_bound(vrow.begin(), vrow.end(), pos_x);
			// if (t != vrow.begin()) t = prev(t);
			// if (pos_x != *t && (idx == col[pos_y].end() || *t > *idx)) inc = pos_x - *t, pos_x = *t + 1;
			// else if (idx == col[pos_y].begin()) inc = pos_x, pos_x = 1;
			// else idx = prev(idx), inc = pos_x - *idx, pos_x = *idx + 1;
			// sum += inc;
			// vcol.push_back(pos_y);
			// sort(vcol.begin(), vcol.end());
		} else {
			// auto idx = lower_bound(row[pos_x].begin(), row[pos_x].end(), pos_y);
			// auto t = lower_bound(vcol.begin(), vcol.end(), pos_y);
			// if (t != vcol.begin()) t = prev(t);
			// if (pos_y != *t && (idx == row[pos_x].end() || *t > *idx)) inc = pos_y - *t, pos_y = *t + 1;
			// else if (idx == row[pos_x].begin()) inc = pos_y, pos_y = 1;
			// else idx = prev(idx), inc = pos_y - *idx, pos_y = *idx + 1;
			// sum += inc;
			// vrow.push_back(pos_x);
			// sort(vrow.begin(), vrow.end());
		}
		cout << pos_x << " " << pos_y << " ";
		cout << sum << " " << tmp << "\n";
		dir = (dir + 1) % 4;
		if (tmp == sum) break;
	}
	if (sum == n * m - k) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}