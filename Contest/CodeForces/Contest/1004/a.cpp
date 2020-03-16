#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, d, a[105], cnt = 0;
	vector<int> v;
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		v.push_back(a[i]-d);
		v.push_back(a[i]+d);
	}
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++) {
		int mn = 1e9 + 7;
		for (int j = 0; j < n; j++) {
			mn = min(mn, abs(v[i]-a[j]));
		}
		if (mn == d) cnt++;
	}
	cout << cnt << "\n";
	return 0;
}