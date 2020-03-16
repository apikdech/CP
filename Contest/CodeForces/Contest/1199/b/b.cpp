/*
 * Author: apikdech
 * Time: 22:03:46 30-07-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	double h, w;
	cin >> h >> w;
	double l = 0, r = 1e15, a;
	for (int i = 0; i < 150; i++) {
		a = (l + r)/2.0;
		if (sqrt(a*a + w*w) < sqrt((a+h)*(a+h))) r = a;
		else l = a;
		// printf("%.6f %.6f\n", sqrt((a+h)*(a+h)), sqrt(a*a + w*w));
	}
	printf("%.10f\n", a);
	return 0;
}
