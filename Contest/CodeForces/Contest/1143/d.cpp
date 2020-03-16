#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
ll n, k, x = 1e10, y = 0, a, b, tmp, l;
int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};

int main() {
	cin >> n >> k >> a >> b;
	for (int i = 0; i < n; i++) {
		l = i*k;
		for (int j = 0; j < 4; j++) {
			tmp = l + dx[j]*a + dy[j]*b;
			if (tmp == 0) tmp = n*k;
			if (tmp < 0) tmp *= -1;
			x = min(x, n*k/__gcd(n*k, tmp));
			y = max(y, n*k/__gcd(n*k, tmp));
		}
	}
	cout << x << " " << y << "\n";
	return 0;
}