/*
 * Author: apikdech
 * Time: 21:43:34 03-06-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
int bs[N];

void sieve() {
	memset(bs, 0, sizeof bs);
	int cnt = 1;
	bs[0] = bs[1] = 1;
	for (int i = 2; i <= N; i++) if (!bs[i]) {
		for (int j = i; j <= N; j += i) bs[j] = cnt;
		cnt++;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	sieve();
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) cout << bs[i] << " \n"[i == n];
	return 0;
}
