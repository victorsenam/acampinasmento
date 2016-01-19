#include <bits/stdc++.h>

using namespace std;

const int N = 10007;

int err;
int n, m;
int a[N];
int res;

int main () {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			scanf(" %c", &c);
			
			a[j] += (c=='W');
			res += (c=='W');
		}
	}

	int ans = -1;
	int mini = res;
	for (int i = 0; i < n; i++) {
		res += m - a[i] - a[i];

		if (res < mini)  {
			mini = res;
			ans = i;
		}
	}

	printf("%d %d\n", ans+1, ans+2);
}
