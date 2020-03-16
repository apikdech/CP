#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int a[105];

int main() {
	int n, dif = -1, ok = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i) {
			if (a[i] != a[i-1]) {
				if (dif == -1) dif = abs(a[i] - a[i-1]);
				else if (abs(a[i] - a[i-1]) != dif) ok = 0;
			}
		} 
	}
	if (ok && dif == -1) cout << "0\n";
	else if (!ok) cout << "-1\n";
	else if (dif & 1) cout << dif << "\n";
	else cout << dif/2 << "\n";
	return 0;
}

// HACKED