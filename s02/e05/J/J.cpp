#include <bits/stdc++.h>
using namespace std;
typedef long long num;
typedef double cood;
typedef complex<cood> point;

const int N = 100;
const cood eps = 1e-9;

int n;
point seg[4*N], curr, ncurr;
cood seen[16*N*N], xin, yin, bin, lx, rx, ans;
int ss, is;

inline cood x(point a)
{ return real(a); }
inline cood y(point a)
{ return imag(a); }
inline cood inner(point a, point b)
{ return x(conj(a)*b); }
inline cood cross(point a, point b)
{ return y(conj(a)*b); }
inline bool parallel(point a, point b, point c, point d)
{ return fabs(cross(b-a, c-d)) < eps; }
inline point intersect(point a, point b, point c, point d)
{ return (a + (b-a)*(cross(c-a,d-c)/cross(b-a,d-c))); }
inline bool between(point a,point b,point c)
{ return fabs(cross(a-c,b-c)) < eps && inner(a-c,b-c) < eps; }

inline cood curr_height(int i, cood x_c)
{
	if( x(seg[i]) < x_c + eps && x_c < x(seg[i|1]) + eps )
			return (x_c - x(seg[i]))*(y(seg[i|1])-y(seg[i]))/(x(seg[i|1])-x(seg[i])) + y(seg[i]);
	else return 0.;
}

int tc;
int main()
{
	tc = 1;
	freopen("skyline.in", "r", stdin);
	while(scanf(" %d", &n) && n)
	{
		ss = is = 0;
		ans = 0.0;
		for(int i=0;i<n;i++)
		{
			scanf(" %lf%lf%lf", &xin, &yin, &bin);
			seg[ss++] = point(xin - .5*bin, 0.);
			seg[ss++] = point(xin, yin);

			seg[ss++] = point(xin, yin);
			seg[ss++] = point(xin + .5*bin, 0.);

			seen[is++] = xin - .5*bin;
			seen[is++] = xin;
			seen[is++] = xin + .5*bin;
		}
		sort(seen, seen+is);
		lx = seen[0];
		rx = seen[is-1];

		for(int i=0;i<ss;i+=2)
			for(int j=i+2;j<ss;j+=2)
				if(!parallel(seg[i], seg[i|1], seg[j], seg[j|1]))
				{
					point loc = intersect(seg[i], seg[i|1], seg[j], seg[j|1]);
					if(!between(seg[i], seg[i|1], loc) || !between(seg[j], seg[j|1], loc)) continue;
					if(y(loc) > eps && lx < x(loc) && x(loc) < rx) seen[is++] = x(loc);
				}
		sort(seen, seen+is);

		curr = point(lx, 0.);
		for(int i=0;i<is;i++)
		{
			cood hi = 0.;
			for(int j=0;j<ss;j+=2)
				hi = max(hi, curr_height(j, seen[i]));
			ncurr = point(seen[i], hi);
			if( max(y(curr), y(ncurr)) > eps)
				ans += abs(ncurr - curr);
			curr = ncurr;
		}
		printf("Case %d: %lld\n\n", tc++, (num)(ans+.5));
	}
}
