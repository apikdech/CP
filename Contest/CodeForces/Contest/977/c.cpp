#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int a[N];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	if (k == 0) {
		if (a[0] == 1) cout << "-1\n";
		else cout << "1\n";
		return 0;
	}
	k--;
	if (a[k] == a[k+1]) cout << "-1\n";
	else cout << a[k] << "\n";
	return 0;
}