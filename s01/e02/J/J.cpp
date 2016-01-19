#include <bits/stdc++.h>

using namespace std;

typedef long long int num;
const int N = 100007;
const int M = 400007;

int c[N], p[N];
int hd[N], to[M], nx[M], es;
num see[N], sal[N];
bool v[N];
int n, m;

bool cmp_p (int i, int j)
{  return c[i] < c[j]; }

int main () { 
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", c+i);
		p[i] = i;
	}

	scanf("%d", &m);

	es = 2;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;	

		nx[es] = hd[a]; hd[a] = es; to[es] = b; es++;
		nx[es] = hd[b]; hd[b] = es; to[es] = a; es++;
	}

	sort(p, p+n, cmp_p);

	int ls = 0;
	num res = 0;
	for (int i = 0; i < n; i++) {
		int u = p[i];

		while (c[p[ls]] < c[u]) {
			see[u] = sal[u];
			for (int ed = hd[p[ls]]; ed; ed = nx[ed]) {
				see[u] = max(see[u], sal[to[ed]]);
			v[p[ls]] = 1;
			ls++;
		}

		sal[u] = 0;
		for (int ed = hd[u]; ed; ed = nx[ed]) {
			sal[u] = max(sal[u], see[to[ed]]);
		}
		sal[u]++;

		printf("%d -> %lld\n", u+1, sal[u]);
		res += sal[u];
	}

	printf("%lld\n", res);
}
