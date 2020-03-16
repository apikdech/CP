/*
 * Author: apikdech
 * Time: 22:01:50 16-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
int a[N], b[N];
bool v[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	memset(v, 0, sizeof v);
	int n, ptr = 0, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == a[ptr]) {
			v[x] = 1;
			while(ptr <= n && v[a[ptr]]) ptr++;	
		}
		else {
			v[x] = 1;
			ans++;
			while(ptr <= n && v[a[ptr]]) ptr++;
		}
		
	}
	cout << ans << '\n';
	return 0;
}
