/**
 * author:  apikdech
 * created: 14.12.2019 18:06:35
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

vector<ll> v;

void pre() {
	for (int i = 1; i <= 9; i++) {
		ll res = i;
		for (int j = 1; j <= 10; j++) {
			v.push_back(res);
			res *= 10;
			res += i;
		}
	}
	sort(v.begin(), v.end());
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	pre();
	// for (int i = 0; i < 50; i++) cout << v[i] << "\n";
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		int idx = lower_bound(v.begin(), v.end(), n) - v.begin();
		if (n == v[idx]) idx++;
		cout << idx << "\n";
	}
	return 0;
}
