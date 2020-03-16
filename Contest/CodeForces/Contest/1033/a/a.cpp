#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	int ax, ay, bx, by, cx, cy;
	cin >> bx >> by >> ax >> ay >> cx >> cy;
	if ((ax < bx && cx < bx && ay < by && cy < by) || (ax > bx && cx > bx && ay > by && cy > by) || (ax > bx && cx > bx && ay < by && cy < by) || (ax < bx && cx < bx && ay > by && cy > by)) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}