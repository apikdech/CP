/*
 * Author: apikdech
 * Time: 21:37:18 16-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
int a[N], af[N], ac[N], sf = 0, sc = 0, sum = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x > 0) af[i] = x/2, ac[i] = (x + 1)/2;
		else af[i] = (x-1)/2, ac[i] = x/2;
		sf += af[i];
		sc += ac[i];
	}
	if (sf == 0) {
		for (int i = 0; i < n; i++) {
			cout << af[i] << "\n";
		}
	} else {
		sf *= -1;
		for (int i = 0; i < n; i++) {
			if (sf) {
				if (af[i] != ac[i]) {
					cout << ac[i] << "\n";
					sum += ac[i];
					sf--;
				}
				else {
					cout << af[i] << "\n";
					sum += af[i];
				}
			} else {
				cout << af[i] << "\n";
				sum += af[i];
			}
		}
	}
	return 0;
}
