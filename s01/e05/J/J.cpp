#include <bits/stdc++.h>
using namespace std;
typedef long long num;
const int N = 1e3+7;

char s[N], in[N], c;
int n, aux, rnk[N], sa[N], lcp[N], f[N];

bool saLess(int i, int j)
{ return strcmp(s+i,s+j) <= 0; }

int main()
{
	while(scanf(" %[ A-Z]", in))
	{
		if(in[0] == '0' && in[1] == 0) break;
		n = strlen(in);

		int m = 0;
		for (int i = 0; i < n; i++) {
			if (in[i] == ' ')
				continue;
			s[m++] = in[i];
		}
		s[n = m++] = 0;
		for(int i=0;i<n;i++) sa[i] = i;
		sort(sa, sa+n, saLess);
		for(int i=0;i<n;i++) rnk[sa[i]] = i;
		int h = 0;
		for(int i=0;i<n;i++)
			if(rnk[i] == n-1) h = 0;
			else
			{
				int j = sa[rnk[i]+1];
				while(i+h<n && j+h<n && s[i+h] == s[j+h]) h++;
				lcp[rnk[i]] = h;
				h -= (!!h);
			}
		lcp[n] = 0;
	//	for (int i = 0; i < n; i++) {
	//		printf("%2d %s\n", lcp[i], s+sa[i]);
	//	}
	//	printf("--\n");
		for (int k = 1; k <= n; k++) {
			int maxi = 0;
			int loc = 0;
			for (int i = 0; i < n-1; i++) {
				if (lcp[i] >= k)
					loc++;
				else
					loc = 0;
				maxi = max(maxi, loc);
			}
			printf("%d\n", maxi+1);
			if (maxi == 0)
				break;
		}
	}
}
