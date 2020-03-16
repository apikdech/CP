#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
vector<ll> v;
ll a, b, ans = 0;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		ans += b*n - a;
		v.push_back(a-b);
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < n; i++) {
		ans += v[i] * (i+1);
	}
	cout << ans << "\n";
	return 0;
}