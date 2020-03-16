#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, cnt;
		string s;
		cin >> n >> s;
		bool flag = true;
		for (int i = 0; i < n/2; i++) {
			cnt = abs(s[i] - s[n-i-1]);
			if (cnt != 0 && cnt != 2) flag = false;
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}