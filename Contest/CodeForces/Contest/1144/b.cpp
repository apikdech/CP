#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
vector<int> o, e;
ll odd = 0, even = 0, n, x, ans;

int main() {
	int n;
	cin >> n;
	while(n--) {
		cin >> x;
		if (x&1) {
			odd++;
			o.push_back(x);
		}
		else {
			even++;
			e.push_back(x);
		}
	}
	sort(o.begin(), o.end());
	sort(e.begin(), e.end());
	if (odd == even) return cout << ans << "\n", 0;
	else if (odd > even) {
		o.pop_back();
		while(e.size()) {
			e.pop_back();
			o.pop_back();
		}
	} else {
		e.pop_back();
		while(o.size()) {
			o.pop_back();
			e.pop_back();
		}
	}
	for (auto i : o) ans += i;
	for (auto i : e) ans += i;
	cout << ans << "\n";
	return 0;
}