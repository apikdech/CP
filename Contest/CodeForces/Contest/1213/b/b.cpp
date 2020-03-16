/*
 * Author: apikdech
 * Time: 21:54:51 30-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;
int a[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, prev = 0, ans = 0;
		priority_queue<int> pq;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		pq.push(a[0]);
		for (int i = 1; i < n; i++) {
			// while(!pq.empty() && a[i] > pq.top()) pq.pop();
			while(!pq.empty() && a[i] < pq.top()) ans++, pq.pop();
			pq.push(a[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}
