#include <bits/stdc++.h>

using namespace std;

const int N = 207;
const int P = 1007;

double memo[N][P];
bool visi[N][P];
int d[N][N];
int v[N][N];
int n, m, p;

double pd (int u, int p) {
	if (p < 0)
		return -1.0/0.0;
	if (p == 0) {
		if (u == 0)
			return 0.0;
		return -1.0/0.0;
	}

	double & me = memo[u][p];
	if(visi[u][p])
		return me;
	visi[u][p] = 1;

	me = -1.0/0.0;

	for (int i = 0; i < n; i++) {
		if (d[u][i] == INT_MAX)
			continue;
			
		me = max(me, pd(i, p-d[u][i]) + v[u][i]);
		me = max(me, pd(u, p-1) + double(v[u][i])/double(d[u][i]));
	}

	return me;
}

int main () {
	scanf("%d %d %d", &n, &m, &p);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			d[i][j] = INT_MAX;

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;

		scanf("%d %d", &d[a][b], &v[a][b]);
		d[b][a] = d[a][b];
		v[b][a] = v[a][b];
	}

	printf("%.20f\n", pd(0, p));
}
