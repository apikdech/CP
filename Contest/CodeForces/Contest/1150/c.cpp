#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 2e5 + 5;
int a[N];

int main() {
	int n, cnt1 = 0, cnt2 = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 1) cnt1++;
		else cnt2++;
	}
	if (cnt1 && cnt2) {
		cout << "2 1 ";
		for (int i = 1; i < cnt2; i++) cout << "2 ";
		for (int i = 1; i < cnt1; i++) cout << "1 ";
	}
	else for (int i = 0; i < n; i++) cout << a[i] << " ";
	return 0;
}