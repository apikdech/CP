#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, ans = 1, p = 0;
	cin >> n;
	while(n) {
		if (n % 10 == 1) ans = max(ans, int(pow(9, p)));
		else if (n % 10) ans = max(ans, max(((n % 10)-1) * int(pow(9, p)), ans * (n % 10)));
		else ans = max(ans, ans * (n % 10));
		// printf("%d %d\n", n, ans);
		n /= 10;
		p++;
	}
	cout << ans << "\n";
	return 0;
}