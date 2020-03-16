#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 2e5 + 5;
vector<int> a, d;
int n, x[N], cnt[N];
bool ok = 1;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		cnt[x[i]]++;
		if (cnt[x[i]] > 2) ok = 0;
	}
	if (!ok) return cout << "NO\n", 0;
	cout << "YES\n";
	sort(x, x+n);
	a.push_back(x[0]);
	for (int i = 1; i < n; i++) {
		if (x[i] == a[a.size()-1]) d.push_back(x[i]);
		else a.push_back(x[i]);
	}
	reverse(d.begin(), d.end());
	cout << a.size() << "\n";
	for (auto i : a) cout << i << " ";
	cout << "\n";
	cout << d.size() << "\n";
	for (auto i : d) cout << i << " ";
	cout << "\n";
	return 0;
}