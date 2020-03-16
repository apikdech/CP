#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 105;
int a[N], ans = 0;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n-1; i++) {
		if (a[i] == 1) continue;
		if (a[i-1] == 1 && a[i+1] == 1) ans++, a[i+1] = 0;
	}
	cout << ans << "\n";
	return 0;
}