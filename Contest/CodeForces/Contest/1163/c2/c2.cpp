/*
 * Author: apikdech
 * Time: 20:57:19 10-05-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 1e3 + 5, INF = 1e6;
const double EPS = 1e-10;
double x[N], y[N];

struct cmp {
	bool operator() (double a, double b) const {
		return (abs(a-b) > EPS) && (a < b);
	}
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, ans = 0, cnt = 0;
	// auto cmp = [](double a, double b) {return (abs(a - b) > EPS) && (a < b);};
	map<double, set<double, cmp>, cmp> m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (x[i] == x[j]) m[0].insert(x[i]);
			else if (y[i] == y[j]) m[INF].insert(y[i]);
			else {
				double g = (y[i] - y[j])/(x[i] - x[j]);
				m[g].insert(y[i] - g*x[i]);
			}
		}
	}
	for (auto it : m) {
		// cerr << "the content of m is ";
		// for (auto x : it.second) cerr << x << " ";
		// cerr << "\n";
		ans += (ll)m[it.first].size() * cnt;
		cnt += (ll)m[it.first].size();
	}
	cout << ans << "\n";
	return 0;
}
