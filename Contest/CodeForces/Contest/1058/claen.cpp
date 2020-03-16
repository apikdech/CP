#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int sum[105];

int main() {
	int n; string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] != '0') break;
		if (i == n-1) return cout << "YES\n", 0;
	}
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i-1] + (s[i-1] - '0');
	}
	int idx = 1, next, res = 0, temp;
	bool flag = false;
	while (idx != n) {
		temp = idx;
		res = sum[idx];
		while(true) {
			//cout << sum[idx] + res << " ";
			next = upper_bound(sum + 1, sum + n + 1, sum[idx] + res) - (sum + 1);
			//next++;
			//cout << idx << " " << next << "\n";
			//cout << sum[idx] + res << " " << sum[next] << "\n\n";
			if (next > n || sum[next] == sum[idx] || (sum[idx] + res) != sum[next]) break; 
			else idx = next;
			if (idx == n) {
				return cout << "YES\n", 0;
			}
		}
		idx = temp;
		idx++;
	}
	cout << "NO\n";
	return 0;
}