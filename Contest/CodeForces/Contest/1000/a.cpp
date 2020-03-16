#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("input", "r", stdin);
	//freopen("output", "w", stdout);
	map<string, int> a, b;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		a[s]++;
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		b[s]++;
	}
	int sum = 0;
	for (auto x : a) {
		if (x.second > b[x.first])
			sum += abs(x.second - b[x.first]);
	}
	cout << sum << "\n";
	return 0;
}