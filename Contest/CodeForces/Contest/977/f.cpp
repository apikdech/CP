#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 2e5 + 5;
int a[N], dp[N], last[N], ans = -1, idx = -1;
map<int, int> pos;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = dp[pos[a[i]-1]] + 1;
		last[i] = pos[a[i]-1];
		pos[a[i]] = i;
		if (ans < dp[i]) ans = dp[i], idx = i;
	}
	cout << ans << "\n";
	vector<int> t;
	while(idx!=0) {
		t.push_back(idx);
		idx = last[idx];
	}
	for (int i = t.size()-1; i >= 0; i--) {
		if (i != 0) cout << t[i] << " ";
		else cout << t[i] << "\n";
	}
	return 0;
}