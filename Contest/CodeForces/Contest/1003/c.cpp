#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, sum[5005], a[5005];
	sum[0] = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0) sum[i+1] = a[i];
		else sum[i+1] = sum[i] + a[i];
	}
	double ans = 0;
	for (int i = k; i <= n; i++) {
		int temp = 0;
		for (int j = 0; j <= n - i; j++) {
			temp = max(temp, sum[i+j] - sum[j]);
		}
		if (temp * 1.0 / i > ans) ans = temp*1.0/i;
	}
	cout << setprecision(15) << ans << "\n";
	return 0;
}