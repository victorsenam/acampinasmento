#include <bits/stdc++.h>

using namespace std;

typedef long long int num;

const int N = 100007;
const int M  = 400007;

int n, m;
num c[N];
multiset<int> s;
multiset<int>::iterator it;
int visi[N];

int hd[N], to[M], nx[M], es;

void dfs (int u) {
	if (visi[u])
		return;
	visi[u] = 1;

	s.insert(c[u]);
	printf("%d -> %lld\n", u, c[u]);

	for (int ed = hd[u]; ed; ed = nx[ed])
		dfs(to[ed]);
}

int main () {
	scanf("%d", &n);

	es = 2;
	for (int i = 0; i < n; i++)
		scanf("%lld", c+i);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		nx[es] = hd[a]; hd[a] = es; to[es] = b; es++;
		nx[es] = hd[b]; hd[b] = es; to[es] = a; es++;
	}

	num res = 0;

	for (int i = 0; i < n; i++) {
		s.clear();
		if (visi[i])
			continue;

		dfs(i);

		num ls = 0;
		num att = 0;
		for (it = s.begin(); it != s.end(); ++it) {
			if (*it != ls) {
				ls = *it;
				att++;
			}

			res += att;
		}
	}

	printf("%lld\n", res);
}
