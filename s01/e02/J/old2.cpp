#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long int num;
typedef int node;
typedef int edge;

const int N = 100007;
const int M = 400007;
int hd[N], p[N], pend[N], lst;
int to[M], nx[M], es;
int n, m, ps;
num P[N], c[N], val[N], sol;

void insert(node u, num x)
{
	val[u] = max(val[u], x);
	for(edge e=hd[u];e!=-1;e=nx[e])
		val[to[e]] = max(val[to[e]], x);
}

num query(node u)
{
	num ans = val[u];
	for(edge e=hd[u];e!=-1;e=nx[e])
		ans = max(ans, val[to[e]]);
	return ans;
}

bool cLess(node u, node v)
{ return mp(c[u], u) < mp(c[v], v); }

int main()
{
	memset(hd, -1, sizeof hd);
	scanf(" %d", &n);
	for(int i=0;i<n;i++) scanf(" %lld", c+i), p[i] = i;
	scanf(" %d", &m);
	while(m--)
	{
		node u, v;
		scanf(" %d%d", &u, &v); --u; --v;
		to[es] = v; nx[es] = hd[u]; hd[u] = es++;
		to[es] = u; nx[es] = hd[v]; hd[v] = es++;
	}
	sort(p, p+n, cLess);
	sol = num(0);
	lst = -1;
	for(int i=0;i<n;i++)
	{
		node u = p[i];
		if(lst != c[u])
		{
			while(ps > 0)
			{
				node v = pend[--ps];
				insert(v, P[v]);
			}
		}
		sol += (P[u] = num(1) + query(u));
		pend[ps++] = u;
		lst = c[u];
	}
	printf("%lld\n", sol);
}
