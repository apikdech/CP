/*
 * Author: apikdech
 * Time: 22:14:16 07-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int a[10][10][10][10];

void pre() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				for (int l = 0; l < 10; l++) {
					if (i == j && j == k && k == l && i == 0) a[i][j][k][l] = 0;
					else if (i == j && k == l && k == 0) a[i][j][k][l] = 0;
					else if (i != j && k == l && k == 0) a[i][j][k][l] = -1;
					else {
						int res = 1e5;
						for (int m = 0; m <= 200; m += 10) {
							
						}
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	pre();
	string s;
	cin >> s;

	return 0;
}
