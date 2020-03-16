#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int a[4];
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	sort(a, a+4);
	for (int i = 0; i < 3; i++) {
		cout << a[3] - a[i] << " ";
	}
	return 0;
}