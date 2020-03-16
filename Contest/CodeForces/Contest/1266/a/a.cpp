/**
 * author:  apikdech
 * created: 17.12.2019 22:07:25
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	while(n--) {
		string s;
		int ok = 0, sum = 0, nol = 0, genap = 0;
		cin >> s;
		for (char c : s) {
			int angka = c - '0';
			if (angka % 2 == 0) genap++;
			if (angka == 0) nol = 1;
			sum += angka;
		}
		if (sum % 3 == 0 && genap >= 2 && nol) cout << "red\n";
		else cout << "cyan\n";
	}
	return 0;
}
