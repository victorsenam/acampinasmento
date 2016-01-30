#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int di[4] = {0, 0, 1, -1};
const int dj[4] = {1, -1, 0, 0};

struct posi {
	int i, j, d;
	bool f;
	ll cost;

	bool operator < (const posi & ot) const
	{ return cost > ot.cost; }
};

const int N = 107;

int n, m;
posi ini, end;
int visi[N][N][2][4], seen[N][N][2][4];
ll dist[N][N][2][4];
int turn;
int cost[N][N][4];

int main () {
	freopen("steam.in", "r", stdin);
	turn = 0;
	while (++turn && scanf("%d %d %d %d %d %d", &n, &m, &ini.i, &ini.j, &end.i, &end.j) && n) {
		ini.i--;
		end.i--;
		ini.j--;
		end.j--;
		priority_queue<posi> pq;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m-1; j++) {
				scanf("%d", &cost[i][j][0]);
				cost[i][j+1][1] = cost[i][j][0];
			}

			if (i < n-1) {
				for (int j = 0; j < m; j++) {
					scanf("%d", &cost[i][j][2]);
					cost[i+1][j][3] = cost[i][j][2];
				}
			}
		}

		ini.cost = 0;
		ini.d = 0;
		ini.f = 1;
		pq.push(ini); // pq fodasse a direção, a flag e 1

		ll res = LLONG_MAX;
		while (!pq.empty()) {
			posi u = pq.top();
			pq.pop();
			
			if (visi[u.i][u.j][u.f][u.d] == turn)
				continue;
			visi[u.i][u.j][u.f][u.d] = turn;

			if (u.i == end.i && u.j == end.j && u.f) {
				res = u.cost;
				break;
			}

			for (int k = 0; k < 4; k++) {
				if (u.f == 0 && k != u.d)
					continue;

				posi nx = u;				
				nx.i += di[k]; nx.j += dj[k]; nx.d = k;
				
				if (nx.i >= n || nx.i < 0 || nx.j >= m || nx.j < 0 || !cost[u.i][u.j][nx.d])
					continue;

				nx.cost += cost[u.i][u.j][nx.d];
				if (u.f)
					nx.cost += cost[u.i][u.j][nx.d];
				nx.f = 0;

				if (seen[nx.i][nx.j][nx.f][nx.d] != turn || dist[nx.i][nx.j][nx.f][nx.d] < nx.cost) {
					dist[nx.i][nx.j][nx.f][nx.d] = nx.cost;
					pq.push(nx);
				}

				if (!u.f)
					nx.cost += cost[u.i][u.j][nx.d];
				nx.f = 1;
				
				if (seen[nx.i][nx.j][nx.f][nx.d] != turn || dist[nx.i][nx.j][nx.f][nx.d] < nx.cost) {
					dist[nx.i][nx.j][nx.f][nx.d] = nx.cost;
					pq.push(nx);
				}
			}
		}

		printf("Case %d: ", turn);
		if (res == LLONG_MAX)
			printf("Impossible\n");
		else
			printf("%lld\n", res);
	}
}
