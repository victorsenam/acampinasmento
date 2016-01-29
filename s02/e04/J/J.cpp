#include <bits/stdc++.h>

using namespace std;

int n;
int val;

int main () {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		int res = 0;

		bool ls = 0;

		for (int j = 0; j < 8; j++) {
			ls = (!!((1 << j)&val))^ls;
			res |= (ls<<j);
		}
		printf("%d ", res);
	}

}
