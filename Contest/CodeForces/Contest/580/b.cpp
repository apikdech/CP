#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end());
	ll ans = 0, diff, sum = 0, l = 0;
	for (int i = 0; i < n; i++) {
		diff = v[i].first - v[l].first;
		while(diff >= m) {
			sum -= v[l].second;
			diff = v[i].first - v[++l].first;
		}
		sum += v[i].second;
		ans = max(ans, sum);
	}
	cout << ans << "\n";
	return 0;
}