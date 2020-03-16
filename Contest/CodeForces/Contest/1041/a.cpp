#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	int a[n+1];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	cout << a[n-1] - a[0] + 1 - n << "\n";
	return 0;
}