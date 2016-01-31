#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
const int N = 103;
const int S = 10000007;

int c[N], e[N], coe[N];
char str[S];
char aux[S];
int n;

int main () {
	int ts = 0;
	while (scanf(" %s", str) != EOF) {
		if (str[0] == '.')
			break;
		int p = 1;
		n = 0;
		while (str[p] != ')') {
			c[n] = 1; e[n] = 1;
			if (str[p] == '-') {
				c[n] = -1;
				p++;
			} else if (str[p] == '+')
				p++;
			
			int l = 0;
			while (isdigit(str[p]))
				aux[l++] = str[p++];
			aux[l++] = 0;
			if (l > 1)
				c[n] *= atoi(aux);
			
			if (str[p] == 'n')
				p++;
			else
				e[n] = 0;
			if (str[p] == '^') {
				p++;

				l = 0;
				while (isdigit(str[p]))
					aux[l++] = str[p++];
				aux[l++] = 0;
				e[n] = atoi(aux);
			}
			n++;
		}
		p++; p++;

		int d = atoi(str+p);
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			sum = (sum+ll(d)+ll(c[i]))%ll(d);
		}

		printf("Case %d: ", ++ts);
		if (sum == 0)
			printf("Always an integer\n");
		else
			printf("Not always an integer\n");
	}
	
	
}
