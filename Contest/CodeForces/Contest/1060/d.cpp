#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;

ll a[N], b, ans, n;
priority_queue<ll> pq;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	ans = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b;
		pq.push(-b);
	}
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++) {
		ans += max(a[i], -pq.top());
		pq.pop();
	}
	cout << ans << "\n";
	return 0;
}