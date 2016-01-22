#include <bits/stdc++.h>

using namespace std;

typedef long long int num;

num n;
num i;

int main () {
	i = 1;

	scanf("%lld", &n);

	printf("1");
	if (n&1) {
		i <<= 1;
		while (i < n) {
			printf(" %lld", i);
			i <<= 1;
		}
	}
	printf("\n");
}
