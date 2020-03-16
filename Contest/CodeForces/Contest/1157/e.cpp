#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 2e5 + 5;
int a[N];
vector<int> ans;
multiset<int> v;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.insert(x);
		v.insert(n+x);
	}
	for (int i = 0; i < n; i++) {
		auto x = v.lower_bound(n - a[i]);
		// cerr << x << " " << v[x] << "\n"; 
		int t = *x;
		ans.push_back((t % n + a[i]) % n);
		v.erase(x);
		if (t >= n) {
			auto y = v.lower_bound(n - t);
			v.erase(y);
		} else {
			auto y = v.lower_bound(t + n);
			v.erase(y);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}