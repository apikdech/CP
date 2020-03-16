#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N = 1e5+5;
int a[N], dp[N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a[x] = i;
		dp[i] = 9;
	}
	for (int i = n; i > 0; i--) {
		int x = a[i];
		if (((x + i) > n) && ((x - i) < 1)) dp[x] = 0;
	}
	// for (int i = 1; i <= n; i++) cout << dp[i] << " " ;
	// cout << "\n";
	for (int i = n; i > 0; i--) {
		int x = a[i];
		for (int j = i; j <= n; j += i) {
			// cout << "HEHE\n";
			if (x + j <= n) dp[x] = min(dp[x], ((dp[x+j]%2 + 1)));
			else break;
		}
		for (int j = i; j <= n; j += i) {
			if (x - j > 0) dp[x] = min(dp[x], (dp[x-j]%2+1));
			else break;
		}
	}
	// for (int i = 1; i <= n; i++) cout << dp[i] << " ";
	for (int i = 1; i <= n; i++) {
		if (dp[i]%2) cout << "A";
		else cout << "B";
	}
	puts ("");
	return 0;
}