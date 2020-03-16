/**
 * author:  apikdech
 * created: 24.11.2019 15:49:44
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
		int n, k, cnt = 0, ok = 1, mn = 0, pos;
		cin >> n >> k;
		string s;
		vector<pair<int, int>> ans;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') cnt++;
			else cnt--;
			if (cnt <= mn) {
				pos = i;
				mn = cnt;
			}

		}
		// cout << s << "\n";
		if (mn < 0) {
			// cout << mn << "\n";
			reverse(s.begin(), s.end());
			// cout << s << "\n";
			ans.push_back({0, n-1});
			cnt = 0, mn = 0;
			for (char c : s) {
				if (c == '(') cnt++;
				else cnt--;
				mn = min(mn, cnt);
			}
			if (mn < 0) {
				reverse(s.begin(), s.begin() + n - pos - 1);
				// cout << s << "\n";
				reverse(s.begin() + n - pos - 1, s.end());
				// cout << s << "\n";
				ans.push_back({0, n - pos - 2});
				ans.push_back({n - pos - 1, n - 1});
			}
		}
		// cout << s << "\n";
		cnt = 0;
		int idx = 0;
		set<pair<int, int>> segs;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') cnt++;
			else cnt--;
			if (cnt == 0) {
				segs.insert({idx, i});
				idx = i+1;
			}
		}
		// cout << s << "\n";
		if (segs.size() == k) {
			cout << ans.size() << "\n";
			for (auto [u, v] : ans) {
				cout << u+1 << " " << v+1 << "\n";
			}
		} else if (segs.size() > k) {
			while(segs.size() > k) {
				auto x = segs.begin();
				segs.erase(x);
				auto y = segs.begin();
				segs.erase(y);
				int l1 = x->first;
				int r1 = x->second;
				int len1 = x->second - x->first + 1;
				int l2 = y->first;
				int r2 = y->second;
				int len2 = y->second - y->first + 1;
				segs.insert({l1, r2});
				for (int i = r1; i >= l1; i--) {
					if (s[i] == '(') {
						ans.push_back({i+1, l2});
						reverse(s.begin() + i + 1, s.begin() + l2 + 1);
						break;
					}
				}
				// ans.push_back({l1 + len1/2, l2 + len2/2 -1});
				// reverse(s.begin() + l1 + len1/2, s.begin() + l2 + len2/2);
				// cout << s << "\n";
			}
			cout << ans.size() << "\n";
			for (auto [u, v] : ans) {
				cout << u+1 << " " << v+1 << "\n";
			}
		} else {
			int cnt = 0;
			set<pair<int, int>> nsegs;
			for (auto [l, r] : segs) {
				if (r-l > 1) nsegs.insert({l, r});
				cnt++;
			}
			while(cnt < k) {
				auto x = nsegs.begin();
				nsegs.erase(x);
				int l = x->first;
				int r = x->second;
				int len = x->second - x->first + 1;
				for (int i = l; i <= r; i++) {
					if (s[i] == '(') continue;
					else {
						// cout << s << "\n";
						// cout << l << " " << r << " " << i << "\n";
						if (len > 4) nsegs.insert({l+2, r});
						ans.push_back({l+1, i});
						// cout << "rev" << l+1 << " " << i << "\n";
						reverse(s.begin() + l + 1, s.begin() + i + 1);
						// cout << s << "\n";
						break;
					}
				}
				// cout << s << "\n";
				cnt++;
			}
			cout << ans.size() << "\n";
			for (auto [u, v] : ans) {
				cout << u+1 << " " << v+1 << "\n";
			}
		}
	}
	return 0;
}
