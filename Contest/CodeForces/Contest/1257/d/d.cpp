/**
 * author:  apikdech
 * created: 13.11.2019 22:42:21
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;

int a[N], st[N][25], n, m, lg[N], prefmax[N], ans = 0, ok = 1;
int p[N], s[N];
map<int, int> tmp;
unordered_map<int, int> idx;
vector<int> v;

void pre() {
	lg[1] = 0;
	for (int i = 2; i < N; i++) {
		lg[i] = lg[i/2] + 1;
	}
}

void build() {
	for (int i = 0; i < n; i++) {
		st[i][0] = a[i];
	}
	for (int j = 1; j < 25; j++) {
		for (int i = 0; i + (1 << j) <= n; i++) {
			st[i][j] = max(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
	for (int i = 0; i < (int)v.size(); i++) {
		if (i) prefmax[i] = max(prefmax[i-1], v[i]);
		else prefmax[i] = v[i];
	}
}

int query(int L, int R) {
	int j = 31 - __builtin_clz(R - L + 1);
	int maximum = max(st[L][j], st[R - (1 << j) + 1][j]);
	return maximum;
}

bool found(int pos, int jarak) {
	int q = query(pos, pos + jarak);
	// cout << pos << " " << pos + jarak << " val : " << q << " ada brp : ";
	jarak++;
	int nHero = prefmax[idx[q]];
	// cout << jarak << " " << cnt << "\n";
	if (nHero >= jarak) return true;
	return false;
}

void reset(int x) {
	tmp.clear();
	v.clear();
	idx.clear();
	for (int i = 0; i <= n; i++) {
		prefmax[i] = 0;
		for (int j = 0; j < 25; j++) st[i][j] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	pre();
	int t;
	cin >> t;
	while(t--) {
		ans = 0, ok = 1;
		cin >> n;
		reset(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			tmp[-a[i]] = 0;
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> p[i] >> s[i];
			tmp[-p[i]] = max(tmp[-p[i]], s[i]);
		}
		int ptr = 0;
		for (auto [key, val] : tmp) {
			idx[-key] = ptr++;
			v.push_back(val);
		}
		build();
		int pos = 0;
		while(pos < n) {
			int l = 0, r = n - pos - 1, m, dist = -1;
			while(l <= r) {
				m = (l + r) >> 1;
				if (found(pos, m)) dist = pos + m, l = m+1;
				else r = m-1;
			}
			if (dist == -1) {
				ok = 0;
				break;
			}
			pos = dist + 1;
			ans++;
		}
		if (!ok || pos != n) cout << "-1\n";
		else cout << ans << "\n";
	}
	return 0;
}
