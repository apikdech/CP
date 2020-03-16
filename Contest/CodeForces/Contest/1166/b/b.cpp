/*
 * Author: apikdech
 * Time: 22:37:21 17-05-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
char ans[105][105];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int k, prime = 1;
  char a[] = {'a', 'i', 'e', 'u', 'o'};
  cin >> k;
  for (int i = 2; i * i <= k; i++) {
    if (k % i == 0) prime = 0;
  }
  if (prime) return cout << "-1\n", 0;
  int x = 0, n = sqrt(k), m;
  while(k % n != 0) n++;
  m = k/n;
  if (n < 5 || m < 5) return cout << "-1\n", 0;
  for (int j = 0; j < m; j++) {
  	for (int i = 0; i < n; i++) {
  		ans[i][j] = a[(i + x) % 5];
  	}
  	x++;
  }
  for (int i = 0; i < n; i++) {
  	for (int j = 0; j < m; j++) {
  		cout << ans[i][j];
  	}
  }
  cout << "\n";
	return 0;
}
