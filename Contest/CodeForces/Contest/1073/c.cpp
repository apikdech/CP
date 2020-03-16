#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int cnt[30];

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int x, y;
	cin >> x >> y;
	if (abs(x) + abs(y) > n || (abs(x) + abs(y)) % 2 != n % 2) cout << "-1\n";
	else {
		for (int i = 0; i < n; i++) {
			cnt[s[i]-'A']++;
		}
		// printf("%d %d %d %d\n", cnt['L' - 'A'], cnt['R' - 'A'], cnt['U' - 'A'], cnt['D' - 'A']);
		if (-cnt['L' - 'A'] + cnt['R' - 'A'] == x && cnt['U' - 'A'] - cnt['D' - 'A'] == y) cout << "0\n";
		else {

		}
	}
	return 0;
}