#include <bits/stdc++.h>

using namespace std;

typedef unsigned int num;

const int N = (1<<24);
const int M = 24;

int n;
num v[N][2];
int p[N];
num a[M];

inline bool p_cmp (int i, int j) {
	if (v[i][1] == v[j][1])
		return v[i][0] < v[j][0];
	return v[i][1] < v[j][1];
}

int main () {
	while (scanf("%d", &n) && n) {
		for (num i = 0; i < n; i++)
			scanf("%u", a+i);
			
		for (num mask = 1; mask < (1u<<n)-1; mask++) {
			v[mask-1][0] = mask;
			v[mask-1][1] = 0;
			for (int j = 0; j < n; j++)
				if (mask & (1u<<j))
					v[mask-1][1] += a[j];
			p[mask-1] = mask-1;
		}

		sort(p, p+(1<<n)-2, p_cmp);

		num mini = 0;
		for (int i = 0; i < n; i++)
			mini += a[i];
		num tot = mini;

		int ls = 0;
		for (int i = 1; i < (1<<n)-2; i++) {
			if (v[p[i]][1] == v[p[ls]][1]) {
				for (int j = ls; j < i; j++)
					if (!(v[p[i]][0]&v[p[j]][0]))
						mini = min(mini, tot-v[p[i]][1]-v[p[j]][1]);
			} else {
				ls = i;
			}
		}
		printf("%u\n", mini);
	}
}
