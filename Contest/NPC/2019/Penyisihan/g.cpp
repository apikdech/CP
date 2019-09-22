/*
 * Author: apikdech
 * Time: 08:44:50 22-09-2019
 * Last Modified: 18:25:48 22-09-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const double EPS = 1e-9;

#define sqr(x) ((x)*(x))

struct point {
  double x,y;
  point(double x1, double y1){x=x1;y=y1;}
};
typedef vector<point> VP;
inline point operator+(point p1, point p2){point p(p1.x+p2.x,p1.y+p2.y); return p;}
inline point operator-(point p1, point p2){point p(p1.x-p2.x,p1.y-p2.y); return p;}
inline double operator*(point p1, point p2){return p1.x*p2.x+p1.y*p2.y;}
inline double operator^(point p1, point p2){return p1.x*p2.y-p1.y*p2.x;}
inline double mag(point p1){return hypot(p1.x,p1.y);}
point inf(1e18,1e18);

vector<point> giftwrap(vector<point> p) {
  vector<point> hull;
  int i,m=0,n=p.size();
  double c;
  for(i=1;i<n;i++)
    if(p[i].x<p[m].x)m=i;
  swap(p[0],p[m]);
  hull.push_back(p[0]);
  for(;;) {
    point b=hull.back();
    m=0;
    for(i=0;i<n;i++) {
      c=(p[i]-b)^(p[m]-b);
      if(c<-1e-9){m=i;continue;}
      if(fabs(c)<1e-9&&mag(p[i]-b)>mag(p[m]-b))m=i;
    }
    if(m==0)return hull;
    hull.push_back(p[m]);
    swap(p[m],p[n-1]);
    p.pop_back();
    n--;
  }
}

// Area of a polygon
double area(vector<point> p) {
  double ret=0;
  int i;
  p.push_back(p[0]);
  for(i=0;i<p.size()-1;i++)
    ret+=p[i].x*p[i+1].y-p[i+1].x*p[i].y;
  if (ret < 0) ret *= -1;
  return ret/2.0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	// cin >> n;
	scanf("%d", &n);
	VP p;
	for (int i = 0; i < n; i++) {
		int a, b;
		// cin >> a >> b;
		scanf("%d %d", &a, &b);
		a++, b++;
		p.push_back(point(a, b));
	}
	p = giftwrap(p);
	// for (auto it : p) cout << it.x << " " << it.y << "\n";
	// cout << fixed << setprecision(2);
	double ans = area(p);
	// if (abs(ans) < EPS) {
	// 	double mnx = 1e9, mny = 1e9, mxx = 0, mxy = 0;
	// 	for (int i = 0; i < p.size(); i++) {
	// 		mnx = min(mnx, p[i].x);
	// 		mxx = max(mxx, p[i].x);
	// 		mny = min(mny, p[i].y);
	// 		mxy = max(mxy, p[i].y);
	// 	}
	// 	double dx = mnx - mxx;
	// 	double dy = mny - mxy;
	// 	// ans = sqrt(dx*dx + dy*dy);
	// 	// ans = 1;
	// 	ans = 0;
	// }
	// cout << ans << "\n";
	printf("%.2f", ans);
	// cerr << "time = " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << " ms\n";
	return 0;
}