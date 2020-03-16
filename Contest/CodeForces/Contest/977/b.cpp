#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, ans = 0;
	string s, res;
	map<string, int> m;
	cin >> n >> s;
	for (int i = 0; i < n-1; i++) {
		string x = "";
		x += s[i];
		x += s[i+1];
		m[x]++;
		if (ans < m[x]) {
			ans = m[x];
			res = x;
		}
	}
	cout << res << "\n";
	return 0;
}