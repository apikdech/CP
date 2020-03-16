/**
 * author:  apikdech
 * created: 15.12.2019 17:31:35
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5;

map<int, vector<int>> m;
int cnt[N];

void path(int x) {
	if (x == 1) {
		// cout << "1 ";
		cnt[1]++;
		return;
	}
	// cout << x << " ";
	cnt[x]++;
	if (x & 1) path(x-1);
	else path(x/2);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		path(i);
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) continue;
		m[cnt[i]].push_back(i);
	}
	for (auto it : m) {
		cout << "len " << it.first << " : ";
		for (auto z : it.second) cout << z << " ";
		cout << "\n";
	}
	return 0;
}
