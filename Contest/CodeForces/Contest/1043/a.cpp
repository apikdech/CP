#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 105;

int main() {
	int n, maks = 0, sum = 0, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		sum += x;
		maks = max(maks, x);
	}
	x = maks * n - sum;
	if (x <= sum) {
		x = 2*sum - maks * n;
		// printf("%d %d\n", x, sum);
		maks += (x+n)/n;
	}
	cout << maks << "\n";
	return 0;
}
