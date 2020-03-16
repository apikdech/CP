#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 1e6 + 5;
ll a[N], cnt[N], sum = 0;
vector<int> ans;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
		sum += a[i];
	}
	for (int i = 0; i < n; i++) {
		sum -= a[i];
		cnt[a[i]]--;
		if (sum % 2 == 0 && sum/2 < N && cnt[sum/2] > 0) ans.push_back(i+1);
		cnt[a[i]]++;
		sum += a[i];
	}
	cout << ans.size() << "\n";
	for (auto i : ans) cout << i << " ";
	return 0;
}