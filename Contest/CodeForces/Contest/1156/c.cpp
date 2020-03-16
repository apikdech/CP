#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 2e5 + 5;
int a[N];

int main() {
	int n, z, ans = 0;
	cin >> n >> z;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	int i = 0;
	for (int j = n/2; j < n; j++) {
		if (i >= n/2) break;
		if (a[j] - a[i] >= z) i++, ans++;
	}
	cout << ans << "\n";
	return 0;
}