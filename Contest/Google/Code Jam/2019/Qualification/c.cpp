#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		string ans = "";
		ll n, l, a[105], g;
		map<ll, int> m;
		cin >> n >> l;
		for (int i = 0; i < l; i++) {
			cin >> a[i];
		}
		g = __gcd(a[0], a[1]);
		vector<ll> v;
		v.push_back(a[0]/g);
		m[a[0]/g]++, m[g]++;
		v.push_back(g);
		for (int i = 1; i < l; i++) {
			if (a[i] % v.back() == 0) g = a[i]/v.back();
			else g = a[i]/(a[i-1]/v.back());
			// printf("%d %d %d %d %d\n", i, a[i], a[i-1], g, __gcd(a[i], a[i-1]));
			m[g]++;
			v.push_back(g);
		}
		int ptr = 0;
		for (auto i : m) m[i.first] = ptr, ptr++;
		for (int i = 0; i < v.size(); i++) ans += char(m[v[i]] + 'A');
		printf("Case #%d: %s\n", tc, ans.c_str());
	}
	return 0;
}