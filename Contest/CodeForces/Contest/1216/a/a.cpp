/*
 * Author: apikdech
 * Time: 14:08:10 21-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, cnt = 0;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n-1; i+=2) {
		if (s[i] == 'a' && s[i+1] == 'b' || s[i] == 'b' && s[i+1] == 'a') continue;
		if (s[i] == 'a') s[i] = 'b', cnt++;
		else s[i] = 'a', cnt++;
	}
	cout << cnt << "\n";
	cout << s << "\n";
	return 0;
}
