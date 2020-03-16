#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 3e5 + 5;
pair<ll, ll> a[N];
priority_queue<ll> pq;
ll sum = 0, ans = 0;

int main() {
	// ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i].second >> a[i].first;
	}
	sort(a, a+n);
	reverse(a, a+n);
	for (int i = 0; i < n; i++) {
		pq.push(-a[i].second);
		sum += a[i].second;
		if (pq.size() > k) {
			sum += pq.top();
			pq.pop();
		}
		ans = max(ans, sum * a[i].first);
	}
	cout << ans << "\n";
	return 0;
}