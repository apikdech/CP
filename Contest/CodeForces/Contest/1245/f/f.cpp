/**
 * author:  apikdech
 * created: 01.11.2019 23:18:52
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1000;

ll f[N];

void pre() {
	f[0] = 0;
	for (int i = 0; i < 400; i++) {
		if (i) f[2 * i] = 2 * f[i] + f[i-1] + 1;
		f[2 * i + 1] = 3 * f[i] + 1;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	pre();
	for (int i = 0; i < 10; i++) cout << f[i] << " ";
	return 0;
}
