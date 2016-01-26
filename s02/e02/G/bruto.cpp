#include <bits/stdc++.h>

using namespace std;

inline int sumdig (int i) {
	int res = 0;
	while (i) {
		res += i%10;
		i/= 10;
	}
	return res;
}

inline bool cmp (int i, int j) {
	int si = sumdig(i); int sj = sumdig(j);
	if (si == sj)
		return i < j;
	return si < sj;
}

const int N = 10000;
int n;
int a[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		a[i] = i +1;
	sort(a, a+n, cmp);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	lprintf("\n");
	
	for (int i = 0; i < n; i++) {
		if (i+1 == a[i])
			printf("%d\n", i+1);
	}
}
