#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int n, ans = 300000, a, c, t, g;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n - 3; i++) {
		a = min(abs(s[i] - 'A'), min(s[i] + 26 - 'A', abs(s[i] - 26 - 'A')));
		c = min(abs(s[i+1] - 'C'), min(s[i+1] + 26 - 'C', abs(s[i+1] - 26 - 'C')));
		t = min(abs(s[i+2] - 'T'), min(s[i+2] + 26 - 'T', abs(s[i+2] - 26 - 'T')));
		g = min(abs(s[i+3] - 'G'), min(s[i+3] + 26 - 'G', abs(s[i+3] - 26 - 'G')));
		cerr << a << " " << c << " " << t << " " << g << "\n";
		ans = min(ans, a + c + t + g);
	}
	cout << ans << "\n";
	return 0;
}