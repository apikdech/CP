#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, a[100005], ans;
	bool visited[100005];
	memset(visited, 0, sizeof visited);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ans = (n * (n-1))/2;
	visited[a[0]] = 1;
	for (int i = 1; i < n-1; i++) {
		if (!visited[a[i]]) visited[a[i]] = 1;
		else ans -= (n-i-1);
	}
	cout << ans << "\n";
	return 0;
}