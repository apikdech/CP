#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, k;
	string s, ans = "", a, b;
	cin >> n >> k >> s;
	for (int i = n-1; i >= 0; i--) {
		a = "", b = "";
		for (int j = 0; j < i; j++) a += s[j];
		for (int j = n-1; j >= n-i; j--) b += s[j];
		reverse(b.begin(), b.end());
		if (a == b)
			break;
	}
	for (int i = a.length(); i < n; i++) ans += s[i];
	cout << s; k--;
	while(k--) cout << ans;
	return 0;
}