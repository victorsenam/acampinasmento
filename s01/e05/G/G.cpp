#include <bits/stdc++.h>

using namespace std;

const int N = 1007;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int n, m;
int q[N*N], qi, qf;
char mat[N][N];
int fir[N][N];
int joe[N][N], jp;

inline bool isval (int i, int j) {
	if (i < 0 || i > n+1)
		return 0;
	if (j < 0 || j > m+1)
		return 0;
	if (mat[i][j] == '#')
		return 0;
	return 1;
}

int main () {
	scanf("%d %d", &n, &m);

	qi = qf = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &mat[i][j]);
			if (mat[i][j] == 'F') {
				q[qf++] = i*(m+2)+j;
			} else {
				fir[i][j] = INT_MAX;
			}

			if (mat[i][j] == 'J') {
				jp = i*(m+2)+j;
			} else {
				joe[i][j] = INT_MAX;
			}
		}

	for (int i = 0; i <= n+1; i++)
		fir[i][0] = fir[i][m+1] = joe[i][0] = joe[i][m+1] = INT_MAX;
	for (int j = 0; j <= m+1; j++)
		fir[0][j] = fir[n+1][j] = joe[0][j] = joe[n+1][j] = INT_MAX;


	while (qi < qf) {
		int u = q[qi++];
		int i = u/(m+2);
		int j = u%(m+2);

		if (i == 0 || i == n+1 || j == 0 || j == m+1)
			continue;

		for (int k = 0; k < 4; k++) {
			int ni = i + dx[k];
			int nj = j + dy[k];

			if (!isval(ni, nj))
				continue;
			if (fir[ni][nj] <= fir[i][j]+1)
				continue;
			fir[ni][nj] = fir[i][j] + 1;

			q[qf++] = ni*(m+2) + nj;
		}
	}
	qi = qf = 0;
	q[qf++] = jp;
	while (qi < qf) {
		int u = q[qi++];
		int i = u/(m+2);
		int j = u%(m+2);

		if (i == 0 || i == n+1 || j == 0 || j == m+1)
			continue;

		for (int k = 0; k < 4; k++) {
			int ni = i + dx[k];
			int nj = j + dy[k];

			if (!isval(ni, nj))
				continue;
			if (joe[ni][nj] <= joe[i][j]+1)
				continue;
			if (fir[ni][nj] <= joe[i][j]+1)
				continue;
			joe[ni][nj] = joe[i][j] + 1;

			q[qf++] = ni*(m+2) + nj;
		}
	}

	int mini = INT_MAX;
	for (int i = 0; i <= n+1; i++) {
		mini = min(mini, joe[i][0]);
		mini = min(mini, joe[i][m+1]);
	}
	for (int j = 0; j <= m+1; j++) {
		mini = min(mini, joe[0][j]);
		mini = min(mini, joe[n+1][j]);
	}


	if (mini == INT_MAX)
		printf("IMPOSSIBLE\n");
	else
		printf("%d\n", mini);
}
