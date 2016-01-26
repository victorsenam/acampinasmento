#include <bits/stdc++.h>

using namespace std;

typedef int num;

const int N = 12;
const int S = 100;
const int P = 2;

int m;
char str[N];
char ans[N];
bool visi[S][N][P];
int memo[S][N][P];

int dp (int s, int d, int pre) {
	if (s < 0) return 0;
	if (d == 0) return (s==0);
	
	num & me = memo[s][d][pre];
	if (visi[s][d][pre])
		return me;
	visi[s][d][pre] = 1;

	me = 0;

	for (int i = 0; i <= 9; i++) {
		if (pre && (str[m-d]-'0' < i))
			break;
		me += dp(s-i, d-1, (pre&&(str[m-d]-'0' == i)));
	}
	return me;
}

void mount (int s, int d, int pre, int k) {
	if (d == 0) {
		ans[m] = 0;
		return;
	}
	
	int summ = 0;
	int i;
	for (i = 0; i <= 9; i++) {
		if (pre && (str[m-d]-'0' < i))
			break;

		int loc = dp(s-i, d-1, (pre&&(str[m-d]-'0' == i)));
		if (summ + loc > k) {
			i++;
			break;
		}
		summ += loc;
	}
	i--;
	
	ans[m-d] = i+'0';
	mount(s-i, d-1, (pre&&(str[m-d]-'0' == i)), k-summ);
}

int main () {
	scanf(" %s", str);
	m = strlen(str);

	int summ = 0;
	int cnt = 0;
	for (int i = 1; i <= 90; i++) {
		int hi = dp(i, m, 1) - 1;
		int lo = 0;

		while (lo < hi) {
			int mid =(hi+lo+1)/2;
			
			mount(i, m, 1, mid);
			int res = atoi(ans);

			if (1 + mid + summ >= res)
				lo = mid;
			else
				hi = mid-1;
		}

		mount(i, m, 1, lo);
		int res = atoi(ans);
		//printf("%d-esimo cara %d\n", lo+summ+1, res);
		if (1+lo + summ == res)
			cnt++;
		summ += dp(i, m, 1);
	}
	printf("%d\n", cnt);
}
