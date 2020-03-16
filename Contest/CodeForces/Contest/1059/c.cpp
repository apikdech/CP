#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, temp = 1, loop, x = 12;
	cin >> n;
	while(n) {
		loop = (n+1) >> 1;
		for (int i = 0; i < loop; i++) {
			cout << temp << " ";
		}
		n -= loop;
		
		if (n + loop == 2) {
			n--;
			cout << temp*2 << "\n";
		}
		else if (n + loop == 3) {
			cout << 3 * temp << "\n";
			n--;
		}
		temp <<= 1;
	}
	return 0;
}
/*
1 2 3 4

1   2 3 4
1   2 4
2   4
4

1 2 3 4 5

1 1 1 2 4

1 2 3 4 5 6

1 1 1 1 3 6

1 1 1 2 2 6

1 2 3 4 5 6 7

1 1 1 1 2 2 6

1 2 3 4 5 6 7 8

1 1 1 1 2 2 4 8

1 1 1 1 2 2 2 8

1 2 3 4 5 6 7 8 9

1 1 1 1 1 sisa 2 4 6 8

1 2 3 4 5 6 7 8 9 10 11 12 13 14

2 4 6 8 10 12 14

bagi 2
1 2 3 4 5 6 7

deretan angka bagi 2
njuk kan jadinya
misal ada 20
nah 10 angka 1
njuk 1 - 10
2 5x
njuk 4 3x
8 8

1 1 1 1 1 1 1 2 2 2 4 4 8
1 1 1 1 1 1 2 2 2 4 4 12
sisa 2 4 6 8 10

misal 4, maksnya itu 6
8 maksnya itu 12
16 maksnya 24 pzti nich

1 sampe 3
njuk 4 sampe 7
*/