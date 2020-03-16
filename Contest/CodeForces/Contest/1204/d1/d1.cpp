/*
 * Author: apikdech
 * Time: 14:48:30 24-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	stack<int> st;
	for (int i = 0; i < s.length(); i++) 
		if (s[i] == '1') st.push(i);
		else if (!st.empty()) st.pop();
	while(!st.empty()) s[st.top()] = '0', st.pop();
	cout << s << "\n";
	return 0;
}
