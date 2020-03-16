#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 3e5 + 5;
int a[N];

int main() {
	int n;
	cin >> n;
	for (int i = 0 ; i < n; i++) {
		cin >> a[i];
	}
	if (a[0] != a[n-1]) cout << n-1 << "\n";
	else {
		int ptr = 0, ans = 0;
		while(a[ptr] == a[n-1]) ptr++;
		ans = max(ans, n-1-ptr);
		ptr = n-1;
		while(a[0] == a[ptr]) ptr--;
		ans = max(ans, ptr);
		cout << ans << "\n";
	}
	return 0;
}