#include <bits/stdc++.h>

using namespace std;

const int N = 70;

int n, k;
int get[N];
int arr[N][N];
int pos[N];
priority_queue<pair<int, int> > pq;
set<int> s;
int res[N][N];

int main () {
	freopen("arrays.in", "r", stdin);
	freopen("arrays.out", "w", stdout);
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &pos[i]);

		for (int j = 0; j < pos[i]; j++)
			scanf("%d", &arr[i][j]);
		sort(arr[i], arr[i]+pos[i]);
	}

	for (int i = 0; i < n; i++)
		pq.push(make_pair(arr[i][--pos[i]], i));	

	int sum = 0;
	
	while (!pq.empty()) {
		pair<int, int> att = pq.top();
		pq.pop();

		if (get[att.second] >= k)
			continue;

		if (s.find(att.first) == s.end()) {
			sum += att.first;
			res[att.second][get[att.second]++] = att.first;
			s.insert(att.first);
		}

		if (pos[att.second]) 
			pq.push(make_pair(arr[att.second][--pos[att.second]], att.second));
	}

	printf("%d\n", sum);

	for (int i = 0; i < n; i++) {
		printf("%d", get[i]);
		for (int j = 0; j < get[i]; j++)
			printf(" %d", res[i][j]);
		printf("\n");
	}
}
