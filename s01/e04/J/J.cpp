#include<bits/stdc++.h>
using namespace std;
typedef long long num;
const int P = 2e6;

int ps;
num primes[P], ans, n;
bool comp[P];

int main()
{
	freopen("job.in", "r", stdin);
	freopen("job.out", "w", stdout);
	for(num i=2;i<P;i++)
		if(!comp[i])
		{
			primes[ps++] = i;
			for(num j=i*i;j<P;j+=i)
				comp[j] = i;
		}

	scanf(" %lld", &n);
	n--;
	ans = 1;
	for(int i=0;i<ps;i++)
		if(n%primes[i] == 0)
		{
			num loc = 1;
			while(n%primes[i] == 0)
				n /= primes[i], loc++;
			ans *= loc;
		}
	if(n > 1) ans *= num(2);
	printf("%lld\n", 1 + ans);
}
