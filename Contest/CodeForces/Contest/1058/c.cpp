#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string s;

bool cek() {
	int l = 0, r = n-1, tl = s[0] - '0', tr = s[n-1] - '0', temp, t = 0, templ, tempr;
	bool flag = false;
	if (tl == tr && n == 2) return true;
	while(l < r) {
		if (tl < tr) {
			l++;
			tl += s[l] - '0';
		} else if (tl > tr) {
			r--;
			tr += s[r] - '0';
		} else if (l > r && (t != tl && t != 0)) {
			l = templ;
			r = tempr;
		} else if (t != tl && t != 0) {
			l++;
			t += s[l] - '0';
		} else if (tl == tr) {
			templ = l, tempr = r;
			t = 0;
			l++;
			t += s[l] - '0';
		}
		if ((t == 0 || t == tl) && (l < r) && tl == tr) {
			flag = true;
			//cout << tl << " " << tr << " " << t <<"\n";
			break;
		}
	}
	if (flag) return true;
	return false;
}

int main() {
	cin >> n >> s;
	puts (cek() ? "YES" : "NO");
	return 0;
}