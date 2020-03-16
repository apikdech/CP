#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, k, ans = 0;
	vector<int> v;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	while(!v.empty() && v.back() <= k) {
		v.pop_back();
		ans++;
	}
	reverse(v.begin(), v.end());
	while(!v.empty() && v.back() <= k) {
		v.pop_back();
		ans++;
	}
	cout << ans << "\n";
	return 0;
}