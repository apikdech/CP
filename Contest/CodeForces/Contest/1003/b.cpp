#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, x, A = 0, B = 0;
	cin >> a >> b >> x;
	string s = "";
	for (int i = 0; i < x; i++) {
		if (i&1) {
			s += '1';
			B++;
		}
		else {
			s += '0';
			A++;
		}
	}
	if (B == b || A == a) {
		while(A < a) {
			s += '0';
			A++;
		}
		while(B < b) {
			s = '1' + s;
			B++;
		}
	}
	else {
		if (x & 1) {
			while(A < a) {
				s = '0' + s;
				A++;
			}
			while(B < b) {
				s += '1';
				B++;
			}
		}
		else {
			while(B < b) {
				s += '1';
				B++;
			}
			while(A < a) {
				s += '0';
				A++;
			}
		}
	}
	cout << s << "\n";
	return 0;
}