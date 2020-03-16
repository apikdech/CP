/**
 * author:  apikdech
 * created: 15.12.2019 16:35:22
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	vector<int> b, w, ans;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'B') b.push_back(i);
		else w.push_back(i);
	}
	if (s.length() & 1) {
		if (b.size() & 1) {
			for (int i = 0; i + 1 < w.size(); i += 2) {
				for (int j = w[i]; j < w[i+1]; j++) {
					ans.push_back(j);
				}
			}
		} else {
			for (int i = 0; i + 1 < b.size(); i += 2) {
				for (int j = b[i]; j < b[i+1]; j++) {
					ans.push_back(j);
				}
			}
		}
	} else {
		if (b.size() & 1 || w.size() & 1) {
			cout << "-1\n";
			return 0;
		}
		else {
			for (int i = 0; i + 1 < b.size(); i += 2) {
				for (int j = b[i]; j < b[i+1]; j++) {
					ans.push_back(j);
				}
			}
		}
	}
	if (!ans.empty()) {
		cout << ans.size() << "\n";
		for (auto it : ans) cout << it+1 << " ";
	} else cout << "0\n";
	return 0;
}
