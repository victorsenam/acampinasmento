#include <bits/stdc++.h>

using namespace std;

const int N = 70;
int ht[20];
char tab[20][N];
int itt[20][N];
int mytime[20][20];
int htt;
char day[N];
int tim;
int n;

int main () {
	scanf("%d", &n);

	for (int i = 0; i < 4; i++)
		ht[i] = 1;

	for (int i = 1; i <= n; i++) {
		htt = 1;
		scanf(" %[a-zA-Z ]", tab[i]);

		int ls = 0;
		int j =0;
		int wr = 0;
		for (j = 0; tab[i][j] != '\0'; j++) {
			if (tab[i][j] == ' ') {
				if (j - ls > 10) {
					htt++;
					ls = wr+1;
					tab[i][wr] = '_';
				}
				wr = j;
			}
		}
		if (j - ls > 10) {
			htt++;
			tab[i][wr] = '_';
		}

		scanf(" %s %d", day, &tim);

		int dd;
		tim--;
		if (day[0] == 'S')
			dd = 2;
		else if (day[1] == 'h')
			dd = 1;
		else
			dd = 0;

		mytime[dd][tim] = i;
		ht[tim] = max(ht[tim], htt);
	}

	printf("+----------+----------+----------+\n");
	for (int j = 0; j < 4; j++) {
		for (int k = 0; k < ht[j]; k++) {
			printf("|");
			for (int i = 0; i < 3; i++) {
				int cnt = 10;
				while (tab[mytime[i][j]][itt[i][j]] != '_' && tab[mytime[i][j]][itt[i][j]]) {
					printf("%c", tab[mytime[i][j]][itt[i][j]]);
					itt[i][j]++;
					cnt--;
				}
				if (tab[mytime[i][j]][itt[i][j]] == '_')
					itt[i][j]++;
				while (cnt--)
					printf(" ");
				printf("|");
			}
			printf("\n");
		}
		printf("+----------+----------+----------+\n");
	}
}
