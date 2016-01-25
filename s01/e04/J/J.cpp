#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
typedef long long num;
const int P = 2e6;

int ps, ds, ws, as, pds, ans;
num primes[P], n;
num d[P], pw[P], aux[P], pnd[2*P];
bool comp[P];

void get_divisors(num x)
{
    ds = 0; d[ds++] = 1;
    for(int i=0;1<x && i<ps;i++)
        if(primes[i]*primes[i] > x) break;
        else if(x%primes[i] == 0)
        {
            num aux = 1;
            ws = 0;
            while(x%primes[i] == 0)
                pw[ws++] = (aux *= primes[i]), x /= primes[i];
            for(int j=0;j<ds;j++)
                for(int k=0;k<ws;k++)
                    d[(k+1)*ds + j] = d[j]*pw[k];
            ds *= (ws+1);
        }
    if(x > 1)
    {
        for(int i=0;i<ds;i++)
            d[ds+i] = x*d[i];
        ds *= 2;
    }
}

int main()
{
    freopen("job.in", "r", stdin);
    freopen("job.out", "w", stdout);
    for(num i=2;i<P;i++)
        if(!comp[i])
        {
            primes[ps++] = i;
            for(num j=i*i;j<P;j+=i) comp[j] = 1;
        }
    scanf(" %lld", &n);
    get_divisors(n);
    for(int i=0;i<ds-1;i++) aux[as++] = d[i];
    ans = ds;

    for(int i=0;i<as;i++)
    {
        get_divisors(n - aux[i]);
        for(int j=0;j<ds;j++)
            if(n%d[j] != 0) pnd[pds++] = d[j];
    }
    sort(pnd, pnd+pds);
    pds = unique(pnd, pnd+pds) - pnd;
    for(int i=0;i<pds;i++)
        if(pnd[i]%(n%pnd[i]) == 0) ans++;
    printf("%d\n", ans);
}
