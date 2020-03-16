/*
 * Author: apikdech
 * Time: 22:47:01 05-07-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
int ans = 0, n, a[N << 2];

pair<int, int> t[N << 2];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) {
  	t[i].first = (t[i<<1].first + t[i<<1|1].first);
  	t[i].second = t[i<<1].second + t[i<<1|1].second + (t[i<<1].first + t[i<<1|1].first >= 10 ? 1 : 0);
  }
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++].first;
    if (r&1) res += t[--r].first;
  }
  return res/10;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + n + i);
	}
	memset(t, 0, sizeof t);
	for (int i = 0; i <= 2*n; i++) t[i].first = a[i];
	build();
	int q;
	scanf("%d", &q);
	while(q--) {
		ans = 0;
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		ans = query(l, r);
		printf("%d\n", ans);
	}
	return 0;
}
