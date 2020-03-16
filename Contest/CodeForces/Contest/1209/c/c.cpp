/*
 * Author: apikdech
 * Time: 20:31:10 14-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 10, M = 2e5 + 5;
int ans[M];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, ok = 1, k = 1;
		cin >> n;
		string s;
		cin >> s;
		for (int i = 0; i < n-1; i++) if (s[i] > s[i+1]) ok = 0;

		if (ok) {
			for (int i = 0; i < n; i++) cout << "1";
			cout << "\n";
		}
		else if (n == 1) cout << "1\n";
		else {
			list<int> a, b;
			a.push_back(s[0]-'0');
			ans[0] = 1;
			for (int i = 1; i < n; i++) {
				if (!b.empty() && s[i] - '0' >= b.back()) b.push_back(s[i] - '0'), ans[i] = 2;
				else if (s[i] - '0' >= a.back()) a.push_back(s[i]-'0'), ans[i] = 1;
				else if (b.empty()) {
					auto rit = a.end(), it = a.begin();
					int j = i-1;
					rit--;
					for (;; rit--, j--) {
						if (*rit > s[i] - '0') it = rit, ans[j] = 2;
						if (rit == a.begin()) break;
					}
					b.splice(b.begin(), b, it, a.end());
					a.push_back(s[i] - '0');
					ans[i] = 1;
				}
			}
			if (a.size() + b.size() != n || b.front() < a.back()) cout << "-\n";
			else {
				for (int i = 0; i < n; i++) cout << ans[i];
				cout << "\n";
			}
			// for (auto it : a) cout << it << " ";
			// cout << "\n";
			// for (auto it : b) cout << it << " ";
			// cout << "\n";
		}
	}
	return 0;
}
