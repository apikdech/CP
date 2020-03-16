/*
 * Author: apikdech
 * Time: 12:40:34 30-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;

int n, BIT[N][30], q;
string s;

void add(int idx, int ch, int val) {
	for (int i = idx; i <= n; i += i & -i) {
		BIT[i][ch] += val;
	}
}

void build() {
	for (int i = 1; i <= n; i++) {
		add(i, s[i] - 'a', 1);
	}
}

int query(int l, int r) {
	int cnt[26][2], res = 0;
	memset(cnt, 0, sizeof cnt);
	for (int i = r; i > 0; i -= i & -i) {
		for (int j = 0; j < 26; j++) {
			cnt[j][0] += BIT[i][j];
		}
	}
	for (int i = l-1; i > 0; i -= i & -i) {
		for (int j = 0; j < 26; j++) {
			cnt[j][1] += BIT[i][j];
		}
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i][0] > cnt[i][1]) res++;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	n = s.length();
	s = ' ' + s;
	build();
	cin >> q;
	while(q--) {
		int opt;
		cin >> opt;
		if (opt == 1) {
			int idx;
			char c;
			cin >> idx >> c;
			add(idx, s[idx] - 'a', -1);
			add(idx, c - 'a', 1);
			s[idx] = c;
		} else {
			int l, r;
			cin >> l >> r;
			cout << query(l, r) << "\n";
		}
	}
	return 0;
}
