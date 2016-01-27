#include <bits/stdc++.h>

using namespace std;

const int N = 4000;
const int di[4] = {1, -1, 0, 0};
const int dj[4] = {0, 0, 1, -1};

int n, m;
char mat[N][N];
bool visi[N][N];
int ns, es;
int res[N][2];

void dfs (int u, int d, int i, int j, bool ls) {
	if (i < 0 || i >= n || j < 0 || j >= m)
		return;
	
	if (mat[i][j] == 79) {
		ns++;
		if (u) {
			res[es][0] = u;
			res[es++][1] = ns;
		}
		int att = ns;
		for (int k = 0; k < 4; k++) {
			if (k != (d^1)) {
				dfs(att, k, i+di[k], j+dj[k], 1);
			}
		}
	} else if( mat[i][j] == 124 && d < 2) {
		dfs(u, d, i+di[d], j+dj[d], 0);
	} else if( mat[i][j] == 45 && d >= 2) {
		dfs(u, d, i+di[d], j+dj[d], 0);
	} else if (mat[i][j] == 43) {
		dfs(u, (d^2), i+di[(d^2)], j+dj[(d^2)], 0);
		dfs(u, (d^3), i+di[(d^3)], j+dj[(d^3)], 0);
	}
}

int main () {
	freopen("picture.in", "r", stdin);
	freopen("picture.out", "w", stdout);
	scanf("%d %d", &n, &m);
	int pi = -1;
	int pj = -1;
	for (int i = 0; i < n; i++) {
		scanf(" %s", mat[i]);
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 79) {
				pi = i; pj = j;
			}
		}
	}

	if (pi == -1 || pj == -1) {
		printf("0\n");
		return 0;
	}

	es = 0;
	dfs(0, 5, pi, pj, 0);

	printf("%d\n", ns);
	for (int i = 0; i < es; i++)
		printf("%d %d\n", res[i][0], res[i][1]);
}
