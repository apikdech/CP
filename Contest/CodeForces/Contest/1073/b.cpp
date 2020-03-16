#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 2e5 + 5;
int a[N], b;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, now = -1, cnt;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a[x] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> b;
		if (now == -1) {
			cnt = a[b];
			now = a[b];
		} else {
			if (a[b] < now) cnt = 0;
			else {
				cnt = a[b] - now;
				now = a[b];
			}
		}
		cout << cnt << " ";
	}
	return 0;
}