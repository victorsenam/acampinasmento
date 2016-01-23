#include <bits/stdc++.h>

using namespace std;

const int N = 2007;

int qtd[4*N][2][2];
int d[4*N][2][2];
int maxi[2];
int mm;
int tot, cnt;
char c;
int n;

int main () {
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %c", &c);

			if (c != '.') {
				qtd[i][0][(c=='X')]++;
				qtd[j][1][(c=='X')]++;
				d[i-j+n][0][(c=='X')]++;

				tot += (c=='X') - (c=='O');
				cnt++;
			}
		}
	}

	for (int i = 0; i < 4*n; i++) {
		for (int k = 0; k < 2; k++) {
			maxi[k] += (qtd[i][0][k] == m);
			maxi[k] += (qtd[i][1][k] == m);
			maxi[k] += (d[i][0][k] == m);
			maxi[k] += (d[i][1][k] == m);
			mm = max(mm, qtd[i][0][k]);
			mm = max(mm, qtd[i][1][k]);
			mm = max(mm, d[i][0][k]);
			mm = max(mm, d[i][1][k]);
		}
	}

	if ((tot != 0 && tot != 1) || (maxi[0] + maxi[1] > 1) || (mm > m)) {
		printf("ERROR\n");
	} else if (maxi[0] == 1) {
		printf("O WINS\n");
	} else if (maxi[1] == 1) {
		printf("X WINS\n");
	} else if (cnt == n*n) {
		printf("DRAW\n");
	} else {
		printf("ERROR\n");
	}
}
