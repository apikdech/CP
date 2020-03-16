#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int a[1005], ans = 0, cnt[1005];

int main() {
	int n, r;
	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i]) {
			ans++;
			for (int j = max(0, i - r + 1); j < min(n, i + r); j++) cnt[j]++;
		}
	}
	for (int i = 0; i < n; i++) if (!cnt[i]) return cout << "-1\n", 0;
	for (int i = 0; i < n; i++) {
		bool flag = true;
		if (a[i]) 
			for (int j = max(0, i - r + 1); j < min(n, i + r); j++) {
				if (cnt[j] == 1) {
					flag = false;
					break;
				}
			}
		if (a[i] && flag) {
			ans--;
			for (int j = max(0, i - r + 1); j < min(n, i + r); j++) cnt[j]--;
		}
	}
	cout << ans << "\n";
	return 0;
}