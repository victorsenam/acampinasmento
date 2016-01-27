#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef int node;
typedef int edge;
const int N = 1e5+3;
const int Q = 1e5+3;
const int M = 2*N;

int n;
int hd[N];
int to[M], nx[M], w[M], es;

int id[N], *leaf, *sz;
int chain[N], d[N], anc[N], tree[2*N];
int ps, ls;

int dfs(node u, node p)
{
	int bst = 0, spc = u;
	sz[id[ps++]=u] = 1;
	d[u] = d[anc[u]=p] + 1;
	for(edge e=hd[u];e!=-1;e=nx[e])
		if(sz[to[e]] == 0)
		{
			sz[u] += dfs(to[e], u);
			if(sz[to[e]] > bst)
				bst = sz[to[e]], spc = to[e];
		}
	if(sz[u] == 1) leaf[ls++] = u;
	return sz[chain[u] = chain[spc] = u];
}

void build(node root)
{
	leaf = tree;
	sz = tree + n;
	ps = ls = 0;
	dfs(root, root);
	for(int i=0;i<n;i++) chain[id[i]] = chain[chain[id[i]]];
	while(ls)
	{
		node u = leaf[--ls];
		while(u != chain[u])
		{
			tree[id[u] = ps++] = 0;
			u = anc[u];
		}
		tree[id[u] = ps++] = 0;
	}
	for(int i=0;i<2*n;i++) tree[i] = 0;
}

int t_query(int l, int r)
{
	int ans = 0;
	for(;l<r;l>>=1,r>>=1)
	{
		if(l&1) ans += tree[l++];
		if(r&1) ans += tree[--r];
	}
	return ans;
}

int query(node u, node v)
{
	if(u == v) return 0;
	int ans = 0;
	while(chain[u] != chain[v])
	{
		if(d[chain[u]] < d[chain[v]]) swap(u,v);
		ans += t_query(id[u], id[chain[u]]+1);
		u = anc[chain[u]];
	}
	if(d[v] > d[u]) swap(u,v);
	return ans + t_query(id[u], id[v]);
}

void update(int p)
{
	if(p < 1) return;
	if(p < n) tree[p] = tree[p<<1] + tree[p<<1|1];
	update(p>>1);
}

int m;
int ans[Q], qu[Q], qv[Q], qk[Q], q[Q], qs;
int e[M], p;

bool kLess(int i, int j)
{ return mp(qk[i], i) < mp(qk[j], j); }
bool wLess(int i, int j)
{ return mp(w[i], i) < mp(w[j],j); }

int main()
{
	memset(hd, -1, sizeof hd);
	freopen("union.in", "r", stdin);
	freopen("union.out", "w", stdout);
	scanf(" %d", &n);
	for(int i=0;i<n-1;i++)
	{
		node u, v; int c;
		scanf(" %d%d%d", &u, &v, &c); --u; --v;
		to[es] = v; nx[es] = hd[u]; w[es] = c; hd[u] = es++;
		to[es] = u; nx[es] = hd[v]; w[es] = c; hd[v] = es;
		e[i] = es++;
	}
	build(0);
	scanf(" %d", &m);
	for(int i=0;i<m;i++)
	{
		scanf(" %d%d%d", qu+i, qv+i, qk+i);
		qu[i]--; qv[i]--;
		q[qs++] = i;
	}
	sort(e, e+es/2, wLess);
	sort(q, q+m, kLess);
	for(int i=0;i<m;i++)
	{
		node u = qu[q[i]],
		     v = qv[q[i]],
			 k = qk[q[i]];
		while(p < n && w[e[p]] <= k)
		{
			node x = d[to[e[p]]] < d[to[e[p]^1]] ? to[e[p]^1] : to[e[p]];
			tree[id[x]] = 1;
			update(id[x]);
			p++;
		}
		ans[q[i]] = query(u, v);
	}
	for(int i=0;i<m;i++) printf("%d\n", ans[i]);
}
