/*
 * Author: apikdech
 * Time: 19:03:39 01-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 105;
int a[N], b[N];
vector<pair<int, int>> pos, neg;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, r;
	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		if (b[i] >= 0) pos.push_back({a[i], b[i]});
		else neg.push_back()
	}
	return 0;
}
