#include <bits/stdc++.h>

using namespace std;

struct evt {
	int time;
	int type;

	bool operator < (const evt & ot) const {
		if (time == ot.time)
			return type > ot.type;
		return time > ot.time;
	}
};

int n, m;
int a, s;
priority_queue<evt> ev;
priority_queue<int> pq;
int cnt;

int main () {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &s);

		evt aux;
		aux.time = a;
		aux.type = 1;
		ev.push(aux);

		aux.time += s;
		aux.type = 0;
		ev.push(aux);
	}

	while (!ev.empty()) {
		evt att = ev.top();

		if (pq.size() && -pq.top() < att.time) {
			pq.pop();
		} else {
			ev.pop();
			if (att.type == 1) {
				if (pq.empty())
					cnt++;
				else
					pq.pop();
			} else {
				pq.push(-att.time-m);
			}
		}
	}

	printf("%d\n", n-cnt);
}
