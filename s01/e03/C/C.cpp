#include <bits/stdc++.h>
#define mp make_pair
#define fst first
#define snd second
using namespace std;
typedef long long num;
const int K = (1<<11)+6;

int k;
num a[10], x;
pair<num, num> curr[K], aux[K];
int cs, as;

void clear_bad()
{
	num l, r;
	cs = 0;
	for(int i=0;i<as;i++)
	{
		l = aux[i].fst;
		r = aux[i].snd;
		if(r < 0) continue;
		if(r == 0) l = r = 0;
		else if(l < 0) l = 0;
		curr[cs++] = mp(l,r);
	}
}

int main()
{
	num l, r;
	scanf(" %d", &k);
	for(int i=0;i<k;i++) scanf(" %lld", a+i);

	x = a[--k];
	aux[as++] = mp(x-1, x+1);
	clear_bad();
	while(k)
	{
		x = a[--k];
		as = 0;
		for(int i=0;i<cs;i++)
		{
			l = curr[i].fst;
			r = curr[i].snd;
			if(l == 0) aux[as++] = mp(x-r, x+r);
			else
			{
				aux[as++] = mp(x-r, x-l);
				aux[as++] = mp(x+l, x+r);
			}
		}
		if(k) clear_bad();
	}
	sort(aux, aux+as);
	printf("%d\n", as);
	for(int i=0;i<as;i++)
		printf("%lld %lld\n", aux[i].fst, aux[i].snd);
}
