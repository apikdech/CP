#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, k, m[30], pos, cur;
	memset(m, 0, sizeof m);
	cin >> n >> k;
	string s;
	cin >> s;
	if (k >= n) cout << "\n";
	else {
		vector<pair<char, int>> v;
		for(int i = 0; i < n; i++) {
			v.push_back(make_pair(s[i], i));
		}
		sort(v.begin(), v.end());
		sort(v.begin()+k, v.end(), [](pair<char, int> a, pair<char, int> b) {return a.second < b.second;});
		for(int i = k; i < n; i++) cout << v[i].first;
		cout << "\n";
	}
	return 0;
}
