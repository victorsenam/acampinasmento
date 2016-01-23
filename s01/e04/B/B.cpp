#include <bits/stdc++.h>

using namespace std;

const int N = 200007;

char str[N];
int pre[N], pos[N];

int main () {
	freopen("bad.in", "r", stdin);
	freopen("bad.out", "w", stdout);
	scanf(" %s", str);
	int n = strlen(str);
	int cnt = 0;


	pos[n] = n;
	for (int i = 0; i < n; i++) {
		if (str[i] == '1')
			pre[i] = i;
		else
			pre[i] = pre[i - !!i];

		if (str[n-i-1] == '1')
			pos[n-i-1] = n-i-1;
		else
			pos[n-i-1] = pos[n-i];

		cnt += (str[i] == '1');
	}

	int mini = INT_MAX;

	for (int i = 0; i < n; i++) {
		mini = min(mini, 2*pre[i] + n - pos[i+1]);
		mini = min(mini, 2*(n-pos[i+1]) + pre[i]);
	}

	printf("%d\n", mini*7 + 4*cnt);
}
