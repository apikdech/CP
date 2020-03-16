/*
 * Author: apikdech
 * Time: 22:13:56 26-06-2019
 * Last Modified: 22:39:01 26-06-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q;
	cin >> q;
	while(q--) {
		int n, ans = 0, aans = 0;
		cin >> n;
		int cnt[n+5], ccnt[n+5], dnt[n+5], ddnt[n+5];
		for (int i = 0; i < n+5; i++) cnt[i] = ccnt[i] = dnt[i] = ddnt[i] = 0;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			cnt[x]++;
			if (y) dnt[x]++;
		}
		for (int i = 1; i <= n; i++) ccnt[cnt[i]]++, ddnt[dnt[i]]++;
		for (int i = n; i >= 1; i--) {
			if (ccnt[i]) {
				ans += i;
				ccnt[i-1] += ccnt[i] - 1;
			}
			if (ddnt[i]) {
				aans += i;
				ddnt[i-1] += ddnt[i] - 1;
			}
		}
		cout << ans << " " << aans << "\n";
	}
	// cerr << "time = " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << " ms\n";
	return 0;
}