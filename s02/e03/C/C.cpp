#include <bits/stdc++.h>
using namespace std;
typedef double cood;
typedef complex<cood> point;
const cood eps = 1e-9;
const cood PI = acos(-1.0);

const int N = 41;

cood r, xin, yin, ans;
point p[N], np[N], c, I[2];
int in, out, n, nps, is;

inline cood x(point a)
{ return real(a); }
inline cood y(point a)
{ return imag(a); }
inline cood inner(point a, point b)
{ return x(conj(a)*b); }
inline cood cross(point a, point b)
{ return y(conj(a)*b); }
bool inside(point a)
{ return abs(a-c) < r; }
inline cood area(point a, point b, point c)
{ return .5*fabs(cross(a-b,c-b)); }
inline int sgn(double x)
{ return (x > eps) - (x < eps); } 
bool inTriangle(point t0, point t1, point t2, point q)
{
	return sgn(cross(t0-t1,t2-t1)) == sgn(cross(t0-t1,q-t1)) &&
	       sgn(cross(t1-t2,t0-t2)) == sgn(cross(t1-t2,q-t2)) &&
	       sgn(cross(t2-t0,t1-t0)) == sgn(cross(t2-t0,q-t0));
}
bool inPoly(point q)
{
	for(int i=1;i<n-1;i++)
		if(inTriangle(p[0],p[i],p[i+1],q)) return 1;
	return 0;
}
point intersect(point a, point b)
{
	if(abs(a-c) < abs(b-c)) return intersect(b,a);
	point dir = (b-a)/abs(b-a);
	double lo = 0, hi = abs(b-a);
	while(fabs(hi-lo) > eps)
	{
		double t = .5*(hi+lo);
		if(inside(a+t*dir)) hi = t;
		else lo = t;
	}
	return a + lo*dir;
}

int main()
{
	freopen("intersection.in", "r", stdin);
	freopen("intersection.out", "w", stdout);
	scanf(" %lf%lf", &xin, &yin);
	c = point(xin, yin);
	scanf(" %lf%d", &r, &n);
	for(int i=0;i<n;i++)
	{
		scanf(" %lf%lf", &xin, &yin);
		p[i] = point(xin, yin);
		if(inside(p[i])) in++;
		else out++;
	}
	if(in == n)
	{
		ans = 0.0;
		for(int i=1;i<n-1;i++)
			ans += area(p[0],p[i],p[i+1]);
		printf("%.10lf\n", ans);
		return 0;
	}
	if(out == n)
	{
		if(inPoly(c)) ans = PI*r*r;
		else ans = 0.0;
		printf("%.10lf\n", ans);
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		int j = (i+1)%n;
		if(inside(p[i]) != inside(p[j]))
			np[nps++] = intersect(p[i], p[j]);
		if(inside(p[j])) np[nps++] = p[j];
	}
	for(int i=0;i<nps;i++)
		if(abs(abs(np[i]-c)-r) < eps) I[is++] = np[i];
	if(is == 1)
		ans = 0.0;
	else
	{
		cood theta = acos(inner(I[0]-c,I[1]-c)/(r*r));
		ans = .5*theta*r*r - area(I[0],I[1], c);
		for(int i=1;i<n-1;i++)
			ans += area(np[0], np[i], np[i+1]);
		printf("%.6lf\n", ans);
	}
}
