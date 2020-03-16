#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

ll f(ll x) {
	if (x == 3) return 6;
	return (x*(x-1)) + f(x-1);
}

int main() {
	int n;
	cin >> n;
	cout << f(n) << "\n";
	return 0;
}