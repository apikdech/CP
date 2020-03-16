/*
 * Author: apikdech
 * Time: 22:59:28 30-07-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 4e5 + 5;
int a[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, ans = 1e6, cnt = 0, last = 1e6, sum = 0;
	map<int, int> m;
	deque<int> dq;
	ll sz;
	cin >> n >> sz;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m[a[i]]++;
	}
	for (auto it : m) {
		cnt++;
		sum += it.second;
		dq.push_front(it.first);
		while (n * (int)(ceil(log2(cnt))) > sz * 8) {
			cnt--;
			sum -= m[dq.back()];
			dq.pop_back();
		}
		ans = min(ans, n-sum);
	}
	cout << ans << "\n";
	return 0;
}
