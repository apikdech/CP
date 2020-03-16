/*
 * Author: apikdech
 * Time: 22:32:04 17-05-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int a[30];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
  	string s;
  	cin >> s;
  	a[s[0]-'a']++;
  }
  for (int i = 0; i < 26; i++) {
  	int x = a[i]/2;
  	int y = a[i] - x;
  	ans += ((x*(x-1))/2);
  	ans += ((y * (y-1))/2);
  }
  cout << ans << "\n";
	return 0;
}
