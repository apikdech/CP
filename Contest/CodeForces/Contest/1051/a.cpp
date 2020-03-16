#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		int ib = -1, ik = -1, in = -1, besar = 0, kecil = 0, num = 0, cnt[105], min = 105;
		memset(cnt, 0, sizeof cnt);
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z') kecil++, cnt[i] = 1;
			else if (s[i] >= 'A' && s[i] <= 'Z') besar++, cnt[i] = 2;
			else num++, cnt[i] = 3;
		}
		if (kecil != 0 && besar != 0 && num != 0) cout << s << "\n";
		else {
			if (num != 0 && besar == 0 && kecil == 0) s[0] = 'a', s[1] = 'A';
			else if (num == 0 && besar != 0 && kecil == 0) s[0] = '1', s[1] = 'a';
			else if (num == 0 && besar == 0 && kecil != 0) s[0] = '1', s[1] = 'A';
			else {
				for (int i = 0; i < s.length(); i++) {
					if (num != 0 && besar != 0) {
						if (num > 1 && cnt[i] == 3) {s[i] = 'a';break;}
						else if (besar > 1 && cnt[i] == 2) {s[i] = 'a';break;}
					}
					if (num != 0 && kecil != 0) {
						if (num > 1 && cnt[i] == 3) {s[i] = 'A';break;}
						else if (kecil > 1 && cnt[i] == 1) {s[i] = 'A';break;}	
					}
					if (besar != 0 && kecil != 0) {
						if (besar > 1 && cnt[i] == 2) {s[i] = '1';break;}
						else if (kecil > 1 && cnt[i] == 1) {s[i] = '1';break;}	
					}
				}
			}
			cout << s << "\n";
		}
	}
	return 0;
}