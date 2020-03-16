#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 2e5 + 5;
ll a[N];
bool cek[N], flag = true;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, sum = 0, x;
	vector<ll> ans;
	cin >> n;
	sum = (n * (n+1))/2;
	for (int i = 0; i < n-1; i++) {
		cin >> a[i];
		sum -= (n-1-i) * a[i];
	}
	if (sum % n || sum <= 0) flag = false;
	else {
		ans.push_back(sum/n);
		for (int i = 0; i < n-1; i++) {
			x = a[i] + ans[i];
			if (x <= 0 || x > n || cek[x]) {
				flag = false;
				break;
			} else {
				cek[x] = true;
				ans.push_back(x);
			}
		}
	}
	if (flag) for (auto it : ans) cout << it << " ";
	else cout << "-1\n";
	return 0;
}