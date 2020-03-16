#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define RESET(a,b) memset(a,b,sizeof(a))
#define INPUT(x, i, n) REP(i, n) cin >> x[i]
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define TIME cout << "time = " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << " ms\n"
#define PRINT(x) cout << x << "\n"
#define gcd __gcd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
const ll MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1);
ll powmod(ll a,ll b, ll m) {ll res=1;a%=m; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%m;a=a*a%m;}return res;}
ll inv(ll n, ll m) {return powmod(n, m-2, m);}

inline void OPEN (string s) {
	freopen ((s + ".in").c_str (), "r", stdin);
	freopen ((s + ".out").c_str (), "w", stdout);
}

int size[200005], v[200005]
vi adj[200005];

void dfs(int n) {
	for(auto u : adj[x]) {
		v[x].pb(u);
		dfs(u);
	}
}

int main() {
	fast
	int n, q, p;
	cin >> n >> q;
	REPN(i, n) {
		if (i == 1) continue;
		cin >> p;
		adj[p].pb(i);
	}
	dfs(1);
	REP(i, q) {
		cnt = 0;
		int u, k;
		cin >> u >> k;
		if (k > size[u]) cout << "-1\n";
	}
	//Enter your code here.
	return 0;
}