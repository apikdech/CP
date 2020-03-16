#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a[1005];
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n-1; i++) {
		if (a[i] >= a[i+1]) v.push_back(a[i]);
	}
	v.push_back(a[n-1]);
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i != v.size()-1) cout << " ";
		else cout << "\n";
	}
	return 0;
}