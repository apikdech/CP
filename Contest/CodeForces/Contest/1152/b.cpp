#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

string to_bin(int x) {
	string res = "";
	while(x) {
		res = (x % 2 ? '1' : '0') + res;
		x /= 2;
	}
	return res;
}

int to_dec(string s) {
	int ans = 0, tmp = 1;
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == '1') ans += tmp;
		tmp <<= 1;
	}
	return ans;
}

int main() {
	int x, cnt = 0;
	vector<int> ans;
	cin >> x;
	string s = to_bin(x);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') {
			ans.push_back(s.length() - i);
			s = to_bin(to_dec(s) ^ ((int)pow(2, (int)s.length() - i) - 1));
			x = to_dec(s);
			cnt++;
			if (x & (x+1)) s = (to_bin(to_dec(s) + 1)), cnt++;
			else break;
		}
	}
	cout << cnt << "\n";
	for (auto it : ans) cout << it << " ";
	return 0;
}