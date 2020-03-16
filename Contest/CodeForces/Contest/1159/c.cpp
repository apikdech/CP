#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 1e5 + 5;
ll a[N], b[N], ans = 0, cnt[N];
bool vis[N], v[N];

int main() {
	int n, m, ok = 1;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[i] = m;
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	sort(a, a+n, greater<int>());
	sort(b, b+m, greater<int>());
	if (a[0] > b[m-1]) return cout << "-1\n", 0;
	for (int i = 0, j = 0; i < n && j < m; j++) {
		if (cnt[i] == 0) i++;
		if (a[i] == b[j]) vis[j] = 1, ans += a[i], cnt[i]--, v[i] = 1;
	}
	for (int i = 0, j = 0; j < m && i < n; j++) {
		if (vis[j]) continue;
		while (v[i] && cnt[i] == 0) i++;
		while (!v[i] && cnt[i] == 1) i++;
		ans += b[j], cnt[i]--, vis[j] = 1;
	}
	for (int i = 0; i < n; i++) {
		ans += cnt[i] * a[i];
	}
	cout << ans << "\n";
	return 0;
}