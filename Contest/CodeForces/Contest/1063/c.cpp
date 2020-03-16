#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int cnt[30];

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	// for (int i = 0; i < n; i++) {
	// 	cnt[s[i]-'a']++;
	// }
	sort(s.begin(), s.end());
	cout << s << "\n";
	return 0;
}