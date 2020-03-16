#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, a = 1, b = 1, c, cnt = 3;
	cin >> n;
	c = n-2;
	if (c % 3 == 0) c--, b++;
	printf("%d %d %d\n", a, b, c);
	return 0;
}