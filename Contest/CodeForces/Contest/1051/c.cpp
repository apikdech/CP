#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[105], h[2], ans[105];

int main() {
	int n, a[105], un = 0, it = 0, flag = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	bool temp = 0;
	for (int i = 0; i < n; i++) {
		if (cnt[a[i]] == 1) {
			un++;
			ans[a[i]] = temp;
			h[temp]++;
			temp ^= 1;
		}
		else if (cnt[a[i]] > 2) {
			it++;
			if (flag == -1) flag = i;
		}
		else {
			ans[a[i]] = 0;
		}
	}
	//printf("%d %d\n", h[0], h[1]);
	if (un & 1 && it == 0) return cout << "NO\n", 0;
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		if (cnt[a[i]] > 2) {
			ans[a[i]] = (h[0] > h[1] ? 0 : 1);
		}
	}
	if ((un & 1) == 0) {
		//cout << "HEHE\n";
		for (int i = 0; i < n; i++) {
			cout << (ans[a[i]] ? 'A' : 'B');
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			if (flag == i) cout << (ans[a[i]] ? 'A' : 'B');
			else cout << (ans[a[i]] ? 'B' : 'A');
		}
	}
	cout << "\n";
	return 0;
}