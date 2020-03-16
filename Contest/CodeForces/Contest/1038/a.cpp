#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, k, cnt[30], ans = 1e5+10;
	for (int i = 0; i < 30; i++) cnt[i] = 0;
	cin >> n >> k;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) cnt[s[i]-'A']++;
	for (int i = 0; i < k; i++) ans = min(ans, cnt[i]);
	cout << ans*k << "\n";
	return 0;
}