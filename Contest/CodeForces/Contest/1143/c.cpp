#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N =1e5 + 5;
vector<int> adj[N], ans;
int n, p, c, x;
bool r[N];

void pre() {
	for (int i = 1; i <= n; i++) r[i] = 1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	pre();
	for (int i = 1; i <= n; i++) {
		cin >> p >> c;
		if (p != -1) adj[p].push_back(i);
		r[p] &= c;
		r[i] &= c;
	}
	for (int i = 1; i <= n; i++) {
		if (r[i]) ans.push_back(i);
	}
	sort(ans.begin(), ans.end());
	if (ans.size()) for (auto i : ans) cout << i << " ";
	else cout << "-1\n";
	return 0;
}