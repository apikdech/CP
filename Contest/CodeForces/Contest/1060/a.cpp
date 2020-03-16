#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, cnt = 0, len, ans = 0;
	char x;
	cin >> n;
	len = n/11;
	for (int i = 0; i < n; i++)	 {
		cin >> x;
		if (x == '8') cnt++;
	}
	ans = min(cnt, len);
	cout << ans << "\n";
	return 0;
}