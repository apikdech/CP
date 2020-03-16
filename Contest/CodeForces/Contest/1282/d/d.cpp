/**
 * author:  apikdech
 * created: 24.12.2019 22:56:34
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

void cek(int n) {
	if (n == 0) exit(0);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, len = 0, a = 0, b = 0;
	string s = "";
	cout << "a" << endl;
	cin >> a;
	cek(n);
	len = max(len, n);
	cout << "b" << endl;
	cin >> b;
	cek(n);
	if (a == b) len = a+1;
	else len = max(a, b);
	if (len == 2) {
		if (a == b) {
			cout << "ab" << endl;
			cin >> n;
			cek(n);
			cout << "ba" << endl;
			cin >> n;
			cek(n);
		} else {
			cout << "aa" << endl;
			cin >> n;
			cek(n);
			cout << "bb" << endl;
			cin >> n;
			cek(n);
		}
	}
	
	return 0;
}
