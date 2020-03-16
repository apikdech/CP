/*
 * Author: apikdech
 * Time: 23:05:45 14-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e6 + 5;
int a[N], frek[N];
vector<int> nol, satu, dua, res[2];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll n, k, mn, mx;
	cin >> n >> k;
	mn = n*(n+1)/2, mx = (n+n/2+1)*(n-n/2);
	if (n & 1) mx -= (n/2 + 1);
	if (k < mn) cout << "-1\n";
	else {
		ll x = n, xcnt, sum = 0;
		x--;
		ll tmp = 0, cnt = 0, sisa;
		k -= mn;
		while(tmp + x <= k) {
			tmp += x;
			cnt++;
			x -= 2;
			if (x <= 0) break;
		}
		xcnt = cnt;
		int ptr = 0;
		sisa = k - tmp;
		x = n;
		while(cnt--) {
			a[ptr] = a[ptr+1] = x;
			ptr += 2;
			x--;
		}
		for (int i = 0; i < n - 2*xcnt - sisa - 1; i++) {
			a[ptr++] = x--;
		}
		a[ptr] = a[ptr+1] = x--;
		ptr += 2;
		for (int i = ptr; i < n; i++) {
			a[i] = x--;
		}
		for (int i = 0; i < n; i++) {
			frek[a[i]]++;
			sum += a[i];
		}
		for (int i = 1; i <= n; i++) {
			if (frek[i] == 0) nol.push_back(i);
			else if (frek[i] == 1) satu.push_back(i);
			else dua.push_back(i);
		}
		for (int i = 0; i < (int)nol.size(); i++) {
			res[0].push_back(nol[i]);
			res[0].push_back(dua[i]);
			res[1].push_back(dua[i]);
			res[1].push_back(nol[i]);
		}
		for (int i = 0; i < (int)satu.size(); i++) {
			res[0].push_back(satu[i]);
			res[1].push_back(satu[i]);
		}
		cout << sum << "\n";
		for (int i = 0; i < 2; i++ ){
			for (int j = 0; j < n; j++) {
				cout << res[i][j] << " \n"[j == n-1];
			}
		}
	}
	return 0;
}
