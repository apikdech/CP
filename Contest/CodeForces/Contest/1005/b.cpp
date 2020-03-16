#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	int len = min(s.length(), t.length()), cnt = 0;
	for (int i = 0; i < len; i++) {
		if (s[s.length()-i-1] == t[t.length()-i-1]) cnt++;
		else break;
	}
	cout << s.length() - cnt + t.length() - cnt << "\n";
	return 0;
}