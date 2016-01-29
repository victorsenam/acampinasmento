#include <bits/stdc++.h>
using namespace std;
typedef long long num;

const int N = 220000;
const int T = 30*N;

int n;
int a[N], b[N], c[N], p[N], in;
int tree[3*N];

num ans;
int l, r, ts;
int x[T], y[T], lc[T], rc[T], sz[T], mx[T];

void update(int t)
{
	if(t == -1) return;
	sz[t] = 1;
	mx[t] = x[t];
	if(lc[t] != -1) sz[t] += sz[lc[t]], mx[t] = max(mx[t], mx[lc[t]]);
	if(rc[t] != -1) sz[t] += sz[rc[t]], mx[t] = max(mx[t], mx[rc[t]]);
}

int merge(int tl, int tr)
{
	int ans = tl;
	if(min(tl,tr) == -1) return max(tl, tr);
	if(y[tl] > y[tr]) rc[tl] = merge(rc[tl], tr);
	else lc[ans=tr] = merge(tl, lc[tr]);
	update(ans);
	return ans;
}

void split(int t, int k)
{
	if(t == -1) return (void)(r = l = -1);
	if(k < x[t]) split(lc[t],k), lc[t] = r, r = t;
	else         split(rc[t],k), rc[t] = l, l = t;
	update(t);
}

int insert(int t, int k)
{
	split(t,k);
	mx[ts] = x[ts] = k;
	lc[ts] = rc[ts] = -1;
	sz[ts] = 1;
	return merge(merge(l, ts++), r);
}

int query(int t, int k)
{
	if(mx[t] < k) return t;
	split(t, k);
	ans += num(r == -1? 0 : sz[r]);
	return merge(l,r);
}

void query(int l, int r, int z)
{
	for(l+=n,r+=n;l<r;l>>=1,r>>=1)
	{
		if(l&1)
		{
			tree[l] = query(tree[l], z);
			l++;
		}
		if(r&1)
		{
			--r;
			tree[r] = query(tree[r], z);
		}
	}
}

void t_insert(int p, int k)
{
	for(p += n; p > 0; p>>=1)
		tree[p] = insert(tree[p], k);
}

bool aLess(int i, int j)
{ return a[i] < a[j]; }

int main()
{
	srand(time(NULL)); rand(); rand();

	scanf(" %d", &n);

	for(int i=0;i<2*n;i++) tree[i] = -1;
	for(int i=0;i<20*n;i++) y[i] = i;
	random_shuffle(y, y+20*n);

	for(int i=0;i<n;i++)
	{
		scanf(" %d", &in);
		a[--in] = i;
	}
	for(int i=0;i<n;i++)
	{
		scanf(" %d", &in);
		b[--in] = i;
	}
	for(int i=0;i<n;i++)
	{
		scanf(" %d", &in);
		c[--in] = i;
	}
	for(int i=0;i<n;i++) p[i] = i;
	sort(p, p+n, aLess);
	for(int i=n-1;i>=0;--i)
	{
		query(b[p[i]], n, c[p[i]]);
		t_insert(b[p[i]], c[p[i]]);
	}
	printf("%lld\n", ans);
}
