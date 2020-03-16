#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, ans = 105;
		cin >> n;
		string s;
		cin >> s;
		if (s[0] == s[n-1] || (s[0] == '>' && s[n-1] == '<')) cout << "0\n";
		else {
			int ptr = 0;
			while(s[ptr] == '<') ptr++;
			ans = min(ans, ptr);
			ptr = n-1;
			while(s[ptr] == '>') ptr--;
			ans = min(ans, n-ptr-1);
			cout << ans << "\n";
		}
	}
	return 0;
}

