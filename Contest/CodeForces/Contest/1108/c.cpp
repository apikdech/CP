#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int a[130], b[130], c[130], ma = -1, mb = -1, mc = -1;
char aa, bb, cc;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (i % 3 == 0) {
			a[s[i]]++;
			//if (a[s[i]] > ma) ma = a[s[i]], aa = s[i];
		}
		else if (i % 3 == 1) {
			b[s[i]]++;
			//if (b[s[i]] > mb) mb = b[s[i]], bb = s[i];
		}
		else {
			c[s[i]]++;
			//if (c[s[i]] > mc) mc = c[s[i]], cc = s[i];
		}
	}
	if (n == 1) {
		cout << 0 << "\n";
		cout << s << "\n";
		return 0;
	}
	else if (n == 2) {
		if (s[0] == s[1]) {
			cout << 1 << "\n";
			if (s[0] == 'R') cout << "RG\n";
			else if (s[0] == 'G') cout << "RG\n";
			else cout << "GB\n";
		}
		else {
			cout << "0\n";
			cout << s << "\n";
		}
		return 0;
	}
	else if (n == 3) {
		if (s[0] == s[1] && s[1] == s[2]) {
			cout << "2\n";
			cout << "RGB\n";
		} else if (s[0] == s[1]) {
			cout << "1\n";
			if (s[2] == 'R') {
				cout << "GBR\n";
			} else if (s[2] == 'G') {
				cout << "RBG\n";
			} else cout << "RGB\n";
		} else if (s[0] == s[2]) {
			cout << "1\n";
			if (s[1] == 'R') cout << "BRG\n";
			else if (s[1] == 'G') cout << "BGR\n";
			else cout << "GBR\n";
		} else if (s[1] == s[2]) {
			cout << "1\n";
			if (s[0] == 'R') cout << "RGB\n";
			else if (s[0] == 'G') cout << "GBR\n";
			else cout << "BGR\n";
		} else {
			cout << "0\n";
			cout << s << "\n";
		}
		return 0;
	}
	vector<int> v;
	v.push_back(a['R'] + a['G'] + a['B']);
	v.push_back(b['R'] + b['G'] + b['B']);
	v.push_back(c['R'] + c['G'] + c['B']);
	sort(v.begin(), v.end());
	if (v[0] == a['R'] + a['G'] + a['B']) ma = 
	if (n % 3 == 0) cout << n - ma - mb - mc << "\n";
	else if (n % 3 == 1) cout << (n + 2)/3 - ma + n/3 - mb + n/3 - mc << "\n";
	else cout << n/3 - ma + (n + 1)/3 - mb + n/3 - mc << "\n";
	for (int i = 0; i < n; i++) {
		if (i % 3 == 0) cout << aa;
		else if (i % 3 == 1) cout << bb;
		else cout << cc;
		if (i == n-1) cout << "\n";
	}
	return 0;
}