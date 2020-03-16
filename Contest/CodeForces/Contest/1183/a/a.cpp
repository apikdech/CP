/*
 * Author: apikdech
 * Time: 21:36:50 26-06-2019
 * Last Modified: 21:38:50 26-06-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a, ok = 0, x;
	cin >> a;
	while(!ok) {
		x = a;
		int sum = 0;
		while(x) {
			sum += x % 10;
			x /= 10;
		}
		if (sum % 4 == 0) ok = 1;
		if (ok) break;
		a++;
	}
	cout << a << "\n";
	// cerr << "time = " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << " ms\n";
	return 0;
}