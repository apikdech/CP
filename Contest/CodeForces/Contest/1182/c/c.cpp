/*
 * Author: apikdech
 * Time: 20:43:14 11-06-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e6 + 5;
vector<string> v[N][10];
vector<string> a[N], b[N];
vector<pair<string, string>> ans_a, ans_b;
vector<int> num;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		char last;
		int cnt = 0;
		cin >> s;
		for (char c : s) {
			if (c == 'a' || c == 'u' || c == 'e' || c == 'i' || c == 'o') cnt++, last = c;
		}
		if (cnt == 0) continue;
		if (last == 'a') v[cnt][0].push_back(s);
		else if (last == 'i') v[cnt][1].push_back(s);
		else if (last == 'u') v[cnt][2].push_back(s);
		else if (last == 'e') v[cnt][3].push_back(s);
		else v[cnt][4].push_back(s);
		num.push_back(cnt);
	}
	sort(num.begin(), num.end());
	num.erase(unique(num.begin(), num.end()), num.end());
	for (int i : num) {
		int az = v[i][0].size();
		int iz = v[i][1].size();
		int uz = v[i][2].size();
		int ez = v[i][3].size();
		int oz = v[i][4].size();
		if (az > 1)
		for (int j = 0; j < az - 1; j+=2) {
			b[i].push_back(v[i][0][j]);
			b[i].push_back(v[i][0][j+1]);
		}
		if (az & 1) a[i].push_back(v[i][0].back());
		if (iz > 1)
		for (int j = 0; j < iz - 1; j+=2) {
			b[i].push_back(v[i][1][j]);
			b[i].push_back(v[i][1][j+1]);
		}
		if (iz & 1) a[i].push_back(v[i][1].back());
		if (uz > 1)
		for (int j = 0; j < uz - 1; j+=2) {
			b[i].push_back(v[i][2][j]);
			b[i].push_back(v[i][2][j+1]);
		}
		if (uz & 1) a[i].push_back(v[i][2].back());
		if (ez > 1)
		for (int j = 0; j < ez - 1; j+=2) {
			b[i].push_back(v[i][3][j]);
			b[i].push_back(v[i][3][j+1]);
		}
		if (ez & 1) a[i].push_back(v[i][3].back());
		if (oz > 1)
		for (int j = 0; j < oz - 1; j+=2) {
			b[i].push_back(v[i][4][j]);
			b[i].push_back(v[i][4][j+1]);
		}
		if (oz & 1) a[i].push_back(v[i][4].back());
	}
	for (int i : num) {
		if (a[i].size() > 1) for (int j = 0; j < a[i].size() - 1; j+=2) ans_a.push_back({a[i][j], a[i][j+1]});
		for (int j = 0; j < b[i].size(); j+=2) {
			ans_b.push_back({b[i][j], b[i][j+1]});
		}
	}
	int asz = ans_a.size(), bsz = ans_b.size();
	x = min(asz, bsz);
	if (bsz > asz) x += (bsz - asz)/2;
	cout << x << "\n";
	for (int i = 0; i < min(asz, bsz); i++) {
		cout << ans_a[i].first << " " << ans_b[i].first << "\n";
		cout << ans_a[i].second << " " << ans_b[i].second << "\n";
	}
	if (bsz > asz + 1) {
		for (int i = asz; i < bsz - 1; i+=2) {
			cout << ans_b[i].first << " " << ans_b[i+1].first << "\n";
			cout << ans_b[i].second << " " << ans_b[i+1].second << "\n";
		}
	}
	return 0;
}
