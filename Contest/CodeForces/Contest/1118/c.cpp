#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int a[25][25], cnt[1005];
vector<int> v;
vector<pair<int, int>> num;

int main() {
	int n, x;
	bool flag = true;
	cin >> n;
	for(int i = 0; i < n*n; i++) {
		cin >> x;
		cnt[x]++;
		if (cnt[x] == 1) v.push_back(x);
	}
	for (int i = 0; i < v.size(); i++) {
		num.push_back({cnt[v[i]], v[i]});
	}
	sort(num.begin(), num.end());
	reverse(num.begin(), num.end());
	if (n == 1) cout << "YES\n" << x << "\n";
	else if (n == 2) {
		if (cnt[x] == 4) cout << "YES\n" << x << " " << x << "\n" << x << " " << x << "\n";
		else cout << "NO\n";
	} else if (n & 1) {
		int odd = 0;
		for (int i = 0; i < v.size(); i++) {
			if (cnt[v[i]] & 1) odd++;
		}
		if (odd > 1) cout << "NO\n";
	} else {
		for (int i = 0; i < v.size(); i++) {
			if (cnt[v[i]] % 4 != 0) {
				flag = false;
				break;
			}
		}
		if (!flag) cout << "NO\n";
		else {
			cout << "YES\n";
			int ptr = 0;
			for (int i = 1; i <= n/2; i++) {
				for (int j = 1; j <= n/2; j++) {
					a[i][j] = a[n-i+1][n-j+1] = a[i][n-j+1] = a[n-i+1][j] = num[ptr].second;
					num[ptr].first -= 4;
					if (num[ptr].first == 0) ptr++;
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					cout << a[i][j];
					if (j != n) cout << " ";
				}
				cout << "\n";
			}
		}
	}
	return 0;
}