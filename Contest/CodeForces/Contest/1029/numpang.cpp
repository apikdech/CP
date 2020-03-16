#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define rep(i,a,b) for(int i=a; i<=b; i++)
#define repp(i,a,b) for(int i=a; i>=b; i--)
#define nrep(i,a,b,c) for(int i=a; i<=b; i+=c)
#define pb push_back
#define ff first
#define ss second
#define nl '\n';
#define sp ' ';
#define inf 1000000007
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
 
	int tc, n, a, t=1;
int main(){ BOOST
	cin>>tc;
	while (tc--){
		pii p[100005];
		cin>>n;
		rep (i, 0, n-1){
			cin>>a;
			p[i]={a, i};
		}
		sort(p, p+n);
		int v[100001]={}, z[100001]={}, ans[100001]={}, idx=0;
		rep (i, 0, n-1){
			v[idx]=p[i].ff;
			z[idx]=p[i].ss;
			idx++;
		}
		cout<<"Kasus #"<<t++<<": ";
		rep (i, 0, n-1){
			ans[z[i]]=lower_bound(v, v+n, v[i])-v;
		}
		rep (i, 0, n-1){
			if (i>0) cout<<" ";
			cout<<ans[i];
		}
		cout<<endl;
	}
	return 0;
}