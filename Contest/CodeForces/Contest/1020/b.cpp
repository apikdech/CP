#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, a[1005];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a[i] = x;
	}
	for (int i = 1; i <= n; i++) {
		int cnt[1005], temp = i;
		memset(cnt, 0, sizeof cnt);
		cnt[temp]++;
		while (cnt[temp] < 2) {
			cnt[a[temp]]++;
			temp = a[temp];
		}
		cout << temp << " ";
	}
	return 0;
}