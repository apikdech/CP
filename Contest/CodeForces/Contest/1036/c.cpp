#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f[20], fact[20], temp[20];

void generate() {
	f[0] = 0,temp[0] = 0;
	for (ll i = 1; i <= 18; i++) {
		if (i <= 3) {
			temp[i] = pow(10, i);
			f[i] = pow(10, i) - temp[i-1];
		}
		else {
			f[i] = 1000*(fact[i]/(fact[i-3]*fact[3])) - temp[i-1];
			temp[i] = 1000*(fact[i]/(fact[i-3]*fact[3]));
		}
		cout << f[i] << "\n";
	}
}

int main() {
	for (int i = 1; i <= 18; i++) {
		if (i == 1) fact[1] = 1;
		else fact[i] = (ll)i * fact[i-1];
	}
	generate();
	int t;
	cin >> t;
	while(t--) {
		ll l, r, ansl = 0, ansr = 0, cnt = 1;
		cin >> l >> r;
		if (l != 1) l--;
		//int pl = log10(l), pr = log10(r);
		//cout << pl << " " << pr << "\n";
		while(l) {
			cout << l << "hw\n";
			ansl += f[cnt]*(l%10);
			cnt++; l /= 10;
		}
		cnt = 1;
		while(r) {
			ansr += f[cnt]*(r%10);
			cnt++; r /= 10;
			//cout << r << " " << ansr << "\n";
		}
		//cout << ansr << " " << ansl << "he\n";
		cout << ansr - ansl << "\n";
	}
	return 0;
}

/*
itung tidak lebih dari 3 non zero
brati bilangan dari 1 sampe 1000 ada 1000 bilangan dong !?
misal bilangan 4 digit
brati zero bisa di posisi 1 2 3 4
if zero ada di pos 1 maka kombinasinya jadi 1 * 10 * 10 * 10 * 4 dongz iya ya itu dari 1 - 10k
5 digit jadinya
1*1*10*10*10*5C2
6 digit
1*1*1*10*10*10*6C3
generalisir bilangan n digit maka jadinya 10^3 * nC(n-3)
misal nih 1024
brati kita call f(1000) + 2 * f(10) + 4 * f(1) gitu kah?
*/