#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int n, m, p[N], r[N], ans = 0, a, b;
bool visited[N], neg[N];

int findSet(int x) {
	return (x == p[x]) ? x : (p[x] = findSet(p[x]));
}

bool isSameSet(int x, int y) {
	return findSet(x) == findSet(y);
}

void unionSet(int x, int y) {
	x = findSet(x), y = findSet(y);
	if (r[x] > r[y]) {
		p[y] = x;
	}
	else {
		p[x] = y;
		if (r[x] == r[y]) r[y]++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) p[i] = i, r[i] = 0, visited[i] = 0, neg[i] = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (!isSameSet(a, b)) {
			int p = findSet(a), q = findSet(b);
			if (!visited[p] && !visited[q]) {
				unionSet(a, b);
			}
			if (visited[p] && !visited[q]) {
				unionSet(a, b);
				int t = findSet(a);
				visited[t] = 1;
				if (!neg[p] && !neg[t]) ans--, neg[p] = neg[t] = neg[a] = neg[b] = 1;
				// else if (neg[p] || neg[t]) neg[p] = neg[t] = 1;
			}
			if (visited[q] && !visited[p]) {
				unionSet(a, b);
				int t = findSet(a);
				visited[t] = 1;
				if (!neg[q] && !neg[t]) ans--, neg[q] = neg[t] = neg[a] = neg[b] = 1;
				// else if (neg[p] || neg[t]) neg[p] = neg[t] = 1;
			}
			if (visited[p] && visited[q]) {
				if (!neg[p]) ans--, neg[p] = 1;
				if (!neg[q]) ans--, neg[q] = 1;
				unionSet(a, b);
			}
		}
		else {
			int t = findSet(a);
			if (visited[t] && !neg[t]) {
				ans--;
				// printf("C %d %d\n", a, b);
				// neg[t] = 1;
				neg[a] = neg[b] = neg[t] = 1;
			}
			if (!visited[t]) {
				visited[a] = visited[b] = visited[t] = 1;
				ans++;
				// visited[t] = 1;
				// printf("B %d %d\n", a[i], b[i]);
			}
		}
	}
	cout << ans << "\n";
	cerr << "time = " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << " ms\n";
	return 0;
}