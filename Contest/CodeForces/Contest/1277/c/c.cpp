/**
 * author:  apikdech
 * created: 14.12.2019 18:33:57
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		string s;
		vector<int> ans;
		cin >> s;
		s += "HEHEHE";
		for (int i = 0; i < s.length() - 5;) {
			if (s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o' && s[i+3] == 'n' && s[i+4] == 'e') ans.push_back(i+2), i += 5;
			else if (s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o') ans.push_back(i+1), i += 3;
			else if (s[i] == 'o' && s[i+1] == 'n' && s[i+2] == 'e') ans.push_back(i+1), i += 3;
			else i++;
		}
		cout << ans.size() << "\n";
		if (ans.size() == 0) cout << "\n";
		for (int i = 0; i < (int)ans.size(); i++) {
			cout << ans[i]+1 << " \n"[i + 1 == (int)ans.size()];
		}
	}
	return 0;
}
