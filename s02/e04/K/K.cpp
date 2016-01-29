#include <bits/stdc++.h>

using namespace std;

typedef long long int num;

const num MAXI = 1e18;
const int N = 200;
const int M = 2007;

int as, bs, cs;
int n, m;
int mat[N][N];
num br[M];
int a, b, c;
int ing[N][N];
int qt[N];
int cnt[M];
num res;
int flag;

inline num multBy(num a, num b)
{
	if(64-__builtin_clzll(a) + 64-__builtin_clzll(b) < 64) return a*b;
	num ans = 0;
	while(b && !flag)
	{
		if(b&1) ans += a;
		flag |= (ans > MAXI);
		a <<= 1;
		b >>= 1;
	}
	return ans;
}

void fail () {
	printf("too many\n");
	exit(0);
}

int main () {
	//printf("%lld\n", multBy(1e18, 1e2));
	//printf("[%d]\n", flag);
	scanf("%d %d %d %d %d", &n, &as, &bs, &cs, &m);

	for (int i = 0; i < n; i++)
		scanf("%lld", br+i);
	
	for (int i = 0; i < as+bs+cs; i++) {
		scanf("%d", qt+i);

		for (int j = 0; j < qt[i]; j++) {
			scanf("%d", &ing[i][j]);
			ing[i][j]--;
		}
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		a--; b--;
		mat[a][b] = mat[b][a] = 1;
	}
	

	num res = 0;
	flag = 0;
	for (int a = 0; a < as; a++) {
		num ma = 1;

		for (int i = 0; i < qt[a]; i++) {
			cnt[ing[a][i]]++;
			ma = multBy(ma, br[ing[a][i]]);
		}

		for (int b = as; b < as+bs; b++) {
			if (mat[a][b])
				continue;

			flag <<= 1;
			num mb = 1;

			for (int i = 0; i < qt[b]; i++) {
				if (!cnt[ing[b][i]])
					mb = multBy(mb, br[ing[b][i]]);
				cnt[ing[b][i]]++;
			}

			for (int c = as+bs; c < as+bs+cs; c++) {
				if (mat[a][c] || mat[b][c])
					continue;
				flag <<= 1;

				num mc = 1;
				for (int i = 0; i < qt[c]; i++) {
					if (!cnt[ing[c][i]])
						mc = multBy(mc, br[ing[c][i]]);
					cnt[ing[c][i]]++;
				}

				num loc = multBy(ma, mb);
				loc = multBy(loc, mc);
				res += loc;
				if (flag || loc > MAXI || res > MAXI || res < 0)
					fail();

				for (int i = 0; i < qt[c]; i++)
					cnt[ing[c][i]]--;
				flag >>= 1;
			}

			for (int i = 0; i < qt[b]; i++)
				cnt[ing[b][i]]--;
			flag >>= 1;
		}
		for (int i = 0; i < qt[a]; i++)
			cnt[ing[a][i]]--;
		flag >>= 1;
	}

	printf("%lld\n", res);
}
