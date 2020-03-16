#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int q;
	cin >> q;
	while(q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a != d) cout << a << " " << d << "\n";
		else if (a != c) cout << a << " " << c << "\n";
		else if (b != c) cout << b << " " << c << "\n";
		else if (b != d) cout << b << " " << d << "\n"; 
		else if (b - a > 1) cout << a + 1 << " " << d << "\n";
		else if (d - c > 1) cout << a << " " << c + 1 << "\n";
		else cout << a << " " << d << "\n";
	}
	return 0;
}