/**
 * author:  apikdech
 * created: 24.11.2019 15:17:03
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
int a[N], cnt[N];

void reset(int n) {
	for (int i = 0; i <= n; i++) cnt[i] = 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, ok = 1, sum = 0;
		cin >> n;
		reset(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt[a[i]]++;
		}
		for (int i = 1; i <= n; i++) {
			sum += cnt[i];
			if (i < sum) ok = 0;
		}
		if (!ok) cout << "-1\n";
		else {
			set<int> s;
			for (int i = 1; i <= n; i++) s.insert(i);
			for (int i = 0; i < n; i++) {
				if (s.count(a[i])) {
					s.erase(a[i]);
					cout << a[i];
				} else {
					int x = *s.begin();
					s.erase(x);
					cout << x;
				}
				if (i + 1 == n) cout << "\n";
				else cout << " ";
			}
		}
	}
	return 0;
}
