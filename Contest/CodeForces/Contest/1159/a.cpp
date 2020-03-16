#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int n, cnt = 0;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (cnt > 0 && s[i] == '-') cnt--;
		else if (s[i] == '+') cnt++;
	}
	cout << cnt << "\n";
	return 0;
}
