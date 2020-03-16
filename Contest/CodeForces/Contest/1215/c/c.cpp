/*
 * Author: apikdech
 * Time: 21:02:39 15-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
vector<int> ab, ba;
vector<pair<int, int>> ans;
int cnt[30];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	for (int i = 0; i < n; i++) {
		cnt[s[i]-'a']++;
		cnt[t[i]-'a']++;
		if (s[i] == t[i]) continue;
		else if (s[i] == 'a' && t[i] == 'b') ab.push_back(i+1);
		else ba.push_back(i+1);
	}
	if ((cnt[0] & 1) || (cnt[1] & 1)) return cout << "-1\n", 0;
	if (ab.size()) 
		for (int i = 0; i < ab.size()-1; i+=2) {
			ans.push_back({ab[i], ab[i+1]});
		}
	if (ba.size())
		for (int i = 0; i < ba.size()-1; i+=2) {
			ans.push_back({ba[i], ba[i+1]});
		}
	if (ab.size() & 1 && ba.size() & 1) {
		ans.push_back({ab.back(), ab.back()});
		ans.push_back({ab.back(), ba.back()});
	}
	cout << ans.size() << "\n";
	for (auto it : ans) cout << it.first << " " << it.second << "\n";
	return 0;
}
