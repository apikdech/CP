/**
 * author:  apikdech
 * created: 24.11.2019 17:21:15
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 105;
int a[N], n, m;
vector<int> num;

map<int, vector<int>> mp;
map<int, int> cnt[N];

void pre() {
	for (int i = 1; i <= min(n, 100); i++) {
		for (int j = 0; j < i; j++) {
			cnt[i][num[j]]++;
		}
	}
	for (int i = 1; i <= min(n, 100); i++) {
		for (int j = 0; j < n; j++) {
			if (cnt[i][a[j]]) {
				mp[i].push_back(a[j]);
				cnt[i][a[j]]--;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		num.push_back(a[i]);
	}
	sort(num.begin(), num.end());
	reverse(num.begin(), num.end());
	pre();
	cin >> m;
	for (int i = 0; i < m; i++) {
		int pos, k;
		cin >> k >> pos;
		cout << mp[k][pos-1] << "\n";
	}
	return 0;
}
