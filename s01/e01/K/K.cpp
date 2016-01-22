#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef int node;
typedef int edge;
const int N = 200000;
const int M = 800000;

int hd[N], rd[N], seen[N], c[N], ord[N], p[N], st[N];
int sol[N];
int n, m, es, os, ss;
int to[M], nx[M];
vector<pair<node, node> > in;

void topSort(node u)
{
	seen[u] = 1;
	for(edge e=hd[u];e!=-1;e=nx[e])
		if(!seen[to[e]]) topSort(to[e]);
	st[ss++] = u;
}

void color(node u, int col)
{
	c[u] = col;
	for(edge e=rd[u];e!=-1;e=nx[e])
		if(c[to[e]] == -1) color(to[e], col);
}

bool lexLess(node u, node v)
{ return mp(c[u], p[u]) < mp(c[v], p[v]); }

int main()
{
	memset(hd, -1, sizeof hd);
	memset(rd, -1, sizeof rd);
	memset(c, -1, sizeof c);
	scanf(" %d%d", &n, &m);
	while(m--)
	{
		node u, v;
		scanf(" %d%d", &u, &v); --u; --v;
		in.push_back(mp(u,v));
	}
	sort(in.begin(), in.end());
	reverse(in.begin(), in.end());
	for(int i=0;i<in.size();i++)
	{
		node u = in[i].first, v = in[i].second;
		to[es] = v; nx[es] = hd[u]; hd[u] = es++;
		to[es] = u; nx[es] = rd[v]; rd[v] = es++;
	}
	for(node u=0;u<n;u++) if(c[u] == -1) color(u, u);
	for(node u=0;u<n;u++) if(!seen[u]) topSort(u);
	while(ss > 0) ord[os++] = st[--ss];
	for(int i=0;i<n;i++) p[ord[i]] = i;
	for(node u=0;u<n;u++) sol[u] = u;
	sort(sol, sol+n, lexLess);
	for(int i=0;i<n;i++) printf("%d ", sol[i]+1);
	putchar('\n');
}
