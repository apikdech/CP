/**
 * author:  apikdech
 * created: 04.11.2019 21:20:03
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		ll n, k, sum = 0, cnt = 0;
		cin >> n >> k;
		string s;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '1') cnt++;
			else {
				if (k <= cnt) {
					int idx = i;
					sort(s.begin(), s.begin() + i);
					// cout << s << "\n";
					// cout << k << "\n";
					while(k) {
						if (idx == 0) break;
						swap(s[idx], s[idx-1]);
						// cout << s << "\n";
						idx--;
						k--;
					}
					break;
				}
				else k -= cnt;
			}
		}
		// cout << k << "\n";
		if (k > 0) sort(s.begin(), s.end());
		cout << s << "\n";

	}
	return 0;
}
