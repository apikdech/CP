/*
 * Author: apikdech
 * Time: 10:09:32 19-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int cnt[150];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (char c : s) {
		cnt[c]++;
	}
	while(cnt['o'] && cnt['n'] && cnt['e']) {
		cout << "1 ";
		cnt['o']--, cnt['n']--, cnt['e']--;
	}
	while(cnt['z'] && cnt['e'] && cnt['r'] && cnt['o']) {
		cout << "0 ";
		cnt['z']--, cnt['e']--, cnt['r']--, cnt['o']--;
	}
	return 0;
}
