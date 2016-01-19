#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 207;
const int M = 2*N*N;
const int P = 1007;


struct tii {
	int u,v,w;
	tii(){}
	tii(int a, int b, int c) : u(a),w(b), v(c){}
};

int n, m, p;
vector<tii> adj[N];
int ed[M][5], d[N], q[N], g[N];
void djs () {
	for (int i = 0; i < n; i++) {
		q[i] = i; 
		d[i] = INT_MAX;
	}

	d[0] = 0;
	vector<tii>::iterator it;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++)
			if (d[q[j]] < d[q[i]])
				swap(q[i], q[j]);

		int at = q[i];
		for(it = adj[at].begin(); it != adj[at].end(); it++){
			if(d[it->u] > d[at] + it->w || (d[it->u] == d[at] + it->w && g[it->u] < g[at] + it->v)){
				d[it->u] = d[at] + it->w;
				g[it->u] = g[at] + it->v;
			}	
		}
	}
	
}

int main () {
	scanf("%d %d %d", &n, &m, &p);

	for (int i = 0; i < m; i++) {
		int s, t,d,v;
		scanf("%d %d %d %d", &s, &t, &d, &v);
		s--; t--;
		adj[s].pb(tii(t,d,v));
		adj[t].pb(tii(s,d,v));
		ed[i][0] = s; ed[i][1] = t; ed[i][2] = v; ed[i][3] = d;
	}

	djs();

	double ans = 0;
	for(int i = 0; i < m; i++){
		if (2*d[ed[i][0]] <= p)
			ans = max(ans, 2.0*double(g[ed[i][0]]) + double(p-2*d[ed[i][0]])*double(ed[i][2])/double(ed[i][3]));
		if (2*d[ed[i][1]] <= p)
			ans = max(ans, 2.0*double(g[ed[i][1]]) + double(p-2*d[ed[i][1]])*double(ed[i][2])/double(ed[i][3]));
			
	}
	printf("%.20f\n",ans);
}
