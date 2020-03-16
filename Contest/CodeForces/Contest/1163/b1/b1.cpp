/*
 * Author: apikdech
 * Time: 20:54:36 10-05-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

const int N = 1e5 + 5;
int cnt[N], ccnt[N];

int main() {
	int n, ans = 0;
	set<int> s, c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		c.insert(x);
		if (ccnt[cnt[x]] == 1) s.erase(cnt[x]);
		if (ccnt[cnt[x]]) ccnt[cnt[x]]--;
		cnt[x]++;
		ccnt[cnt[x]]++;
		s.insert(cnt[x]);
		if (s.size() == 1) {
			if(c.size() == 1) ans = i+1;
			else if (*s.begin() == 1) ans = i+1;
		}
		else if (s.size() == 2) {
			int id = *s.begin();
			auto idx = s.begin();
			idx++;
			int tmp = *idx;
			if (ccnt[id] == 1 && id == 1) ans = i+1;
			else if (ccnt[tmp] == 1 && tmp - id == 1) ans = i+1;
		}
	}
	cout << ans << "\n";
	return 0;
}