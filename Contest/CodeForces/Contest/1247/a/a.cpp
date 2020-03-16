/**
 * author:  apikdech
 * created: 01.11.2019 06:20:23
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int getLeft(int x) {
	int last = 0;
	while(x) {
		last = x % 10;
		x /= 10;
	}
	return last;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int a, b;
	pair<int, int> ans = {-1, -1};
	cin >> a >> b;
	for (int i = 1; i < 100; i++) {
		if (getLeft(i) == a && getLeft(i+1) == b) {
			ans = {i, i+1};
			break;
		}
	}
	if (ans != (pair<int, int> (-1, -1))) cout << ans.first << " " << ans.second << "\n";
	else cout << -1 << "\n";
	return 0;
}
