/*
 * Author: apikdech
 * Time: 20:48:06 15-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int sumL = 0, sumR = 0, qL = 0, qR = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, ok;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n/2; i++) {
		if (s[i] == '?') qL++;
		else sumL += s[i] - '0';
	}
	for (int i = n/2; i < n; i++) {
		if (s[i] == '?') qR++;
		else sumR += s[i] - '0';
	}
	// cout << sumL << " " << sumR << "\n";
	// cout << qL << " " << qR << "\n";
	if (sumL == sumR) {
		if (qL == qR) ok = 1;
		else ok = 0;
	} else if (sumL > sumR) {
		if (qL >= qR) ok = 0;
		else {
			sumL -= sumR;
			qR -= qL;
			qR /= 2;
			if (sumL % 9 == 0 && sumL/9 == qR) ok = 1;
			else ok = 0;
		}
	} else {
		if (qR >= qL) ok = 0;
		else {
			sumR -= sumL;
			qL -= qR;
			qL /= 2;
			if (sumR % 9 == 0 && sumR/9 == qL) ok = 1;
			else ok = 0;
		}
	}
	if (ok) cout << "Bicarp\n";
	else cout << "Monocarp\n";
	return 0;
}
