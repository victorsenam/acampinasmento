#include <bits/stdc++.h>

using namespace std;

typedef long long int num;
typedef pair<int, num> pii;

const int N = 100007;
const int M = 256;

int n;
num a[N];
char str[3];
pii memo[N][M];
bool visi[N][M];

pii pd (int i, int q) {
	if (i == 0)
		return pii(0, 0llu);

	pii & me = memo[i][q];
	if (visi[i][q])
		return me;
	visi[i][q] = 1;

	me = pd(i-1, q?q-1:255);
	me.second += !!q;
	me.first += a[i]^q + 256*me.second;

	if (i == q)
		return me;
	me = max(me, pd(i-1, q));

	return me;
}

num convert () {
	num res = 0;

	if (isdigit(str[0]))
		res += str[0]-'0';
	else
		res += str[0]+10-'A';
	res *= 16;

	if (isdigit(str[1]))
		res += str[1]-'0';
	else
		res += str[1]+10-'A';
	
	return res;
}

int main () {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf(" %s", str);
		a[i] = convert();	
	}
	pii ans = pd(n, 0);
	for (int i = 0; i < max(n+1, 256); i++)
		ans = max(ans, pd(n, i));
	
	printf("%lld\n", ans.first);
}
