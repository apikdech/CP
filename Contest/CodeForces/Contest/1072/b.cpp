#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
int a[N], b[N], n;
vector<int> ans;

void dfs(int x) {
	if (x == n) {
		cout << "YES\n";
		for (auto u : ans) cout << u << " ";
		exit(0);
	}
	int t = ans[ans.size()-1];
	for (int i = 0; i <= 3; i++) {
		if ((i | t) == a[x-1] && (i & t) == b[x-1]) {
			ans.push_back(i);
			dfs(x + 1);
			ans.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 0; i < n-1; i++) cin >> a[i];
	for (int i = 0; i < n-1; i++) cin >> b[i];
	ans.push_back(0);
	dfs(1);
	ans[0] = 1;
	dfs(1);
	ans[0] = 2;
	dfs(1);
	ans[0] = 3;
	dfs(1);
	cout << "NO\n";
	return 0;
}