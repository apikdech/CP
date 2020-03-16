#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)
typedef long long ll;

double x[3], y[3], ans = 0, eps = 1e-4, a, b, c, A, B, C, s, n, l, r;

double gcd(double x, double y) {
    while(fabs(x) > eps && fabs(y) > eps) {
        if (x > y)
            x -= floor(x/y)*y;
        else 
            y -= floor(y/x)*x;
    }
    return x+y;
}

double dist(double x1, double y1, double x2, double y2) {
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double deg(double p, double q, double r) {
	return acos((q*q + r*r - p*p)/(2*q*r));
}

double area(double p, double q, double r) {
	s = (a+b+c)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main() {
	for (int i = 0; i < 3; i++) {
		cin >> x[i] >> y[i];
	}
	a = dist(x[0],y[0],x[1],y[1]);
	b = dist(x[0],y[0],x[2],y[2]);
	c = dist(x[1],y[1],x[2],y[2]);
	l = area(a, b, c);
	r = (a*b*c)/(4*l);
	A = deg(a, b, c);
	B = deg(b, a, c);
	C = deg(c, a, b);
	// printf("%.2f %.2f %.2f\n", A, B, C);
	n = PI/gcd(gcd(A, B), C);
	// printf("%.2f %.2f\n", n, r);
	ans = n*r*r*sin(2*PI/n)/2;
	// ans = acos(-1);
	printf("%.6f\n", ans);
	return 0;
}