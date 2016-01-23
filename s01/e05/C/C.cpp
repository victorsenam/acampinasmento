#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef double cood;

const int N = 1e5+2;
const int S = 1e6+7;
const cood eps = 1e-9;

int s[S];
int x[N], y[N], p[N];
int W, v, n, ss;

int solve(int j)
{
	cood tan = 1.*s[j]/v;
	cood ll = x[p[0]];
	cood lr = x[p[0]] + W;
	int ly = y[p[0]];
	for(int i=1;i<n;i++)
	{
		int k = p[i];
		cood dx = 1.*v*cood(ly-y[k])/cood(s[j]);
		cood nl = max(cood(x[k])  , ll - dx);
		cood nr = min(cood(x[k]+W), lr + dx);
		if(nr-nl < -eps) return 0;
		ll = nl;
		lr = nr;
		ly = y[k];
	}
	return 1;
}

bool lexLess(int i, int j)
{ return mp(y[j],x[j]) < mp(y[i],x[i]); }
int main()
{
	scanf(" %d%d%d", &W, &v, &n);
	for(int i=0;i<n;i++) scanf(" %d%d", x+i, y+i), p[i] = i;
	sort(p, p+n, lexLess);

	scanf(" %d", &ss);
	for(int i=0;i<ss;i++) scanf(" %d", s+i);
	sort(s,s+ss);
	ss = unique(s,s+ss) - s;

	if(!solve(0))
	{
		puts("IMPOSSIBLE");
		return 0;
	}

	int lo = 0, hi = ss-1;
	while(lo < hi)
	{
		int mid = lo + (1+hi-lo)/2;
		if(solve(mid)) lo = mid;
		else hi = mid-1;
	}
	printf("%d\n", s[lo]);
}
