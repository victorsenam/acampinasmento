#include <bits/stdc++.h>
using namespace std;
typedef long long num;
const int N = 2000;

int n, a, b, legal;
int in[N], acc[N];

int main()
{
	scanf(" %d", &n);
	while(n--)
	{
		scanf(" %d%d", &a, &b);
		for(int i=a;i<=b;i++) in[i] = 1;
	}
	
	int cnt = 0;
	for (int i = 0; i < 180; i++)
		cnt += in[i];
	if (cnt > 90) {
		printf("No\n");
		return 0;
	}

	for (int i = 180; i < N; i++) {
		cnt += in[i];
		cnt -= in[i-180];
		
		if (cnt > 90) {
			printf("No\n");
			return 0;
		}
	}

	printf("Yes\n");
}
