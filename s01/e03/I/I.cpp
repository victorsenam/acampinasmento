#include <bits/stdc++.h>
using namespace std;
typedef long long num;
const num MOD = 1e9+7;
const int N = 5005;

struct mod
{
	int x;
	mod() {}
	mod(int a) : x(a%MOD) {} 
	mod operator+(const mod& b) const { return (num(x)+num(b.x))%MOD; }
	mod operator-(const mod& b) const { return (MOD+num(x)-num(b.x))%MOD; }
	mod operator*(const mod& b) const { return (num(x)*num(b.x))%MOD; }
};

mod fact[N], ans;
mod fexp(mod a, int e)
{
	mod t = 1;
	while(e)
	{
		if(e&1) t = t*a;
		a = a*a;
		e >>= 1;
	}
	return t;
}
mod comb(int a, int b)
{
	if(a == 0 && b == 0) return 1;
	if(a == 0 || a < b) return 0;
	mod den = fact[b]*fact[a-b];
	den = fexp(den, MOD-2);
	return fact[a]*den;
}

int c[N];
int n, t, k, p;
int qmn, qma, T;
int main()
{
	ans = 0;
	fact[0] = 1;
	for(int i=1;i<N;i++) fact[i] = fact[i-1]*mod(i);
	scanf(" %d%d", &n, &t);
	for(int i=0;i<n;i++) scanf(" %d", c+i);
	scanf(" %d%d", &k, &p); k--; p--;

	for(int i=0;i<n;i++)
		if(c[i] == c[k]) T++;
		else if(c[i] < c[k]) qmn++;
		else qma++;

	ans = comb(n-1, t-1);
	for(int i=p+1;i<t;i++) ans = ans - comb(qmn, i)*comb(qma + T-1, t-i-1);
	for(int i=t-p;i<t;i++) ans = ans - comb(qma, i)*comb(qmn + T-1, t-i-1);
	printf("%d\n", ans.x);
}
