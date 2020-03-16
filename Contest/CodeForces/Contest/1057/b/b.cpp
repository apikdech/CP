#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 5005;
int a[N], sum[N], n, ans = 0;

int main() {
	cin >> n;
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (sum[i] - sum[j] > 100*(i-j)) {
				ans = max(ans, i-j);
			}
			// printf("%d %d %d %d %d\n", i, j, sum[i], sum[j], sum[i] - sum[j]);
		}
	}
	cout << ans << "\n";
	return 0;
}