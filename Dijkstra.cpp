#include<bits/stdc++.h>
#define MAXM 1020
#define MAXN 10000
#define INF 0x3f3f3f

struct edge
{
	int nxt, to;
	int dis;
}e[MAXM];
int head[MAXM], num = 0;
int dis[MAXN];
bool used[MAXN] = {0};
int n, m;
int x, y, z;
int u, minn;

void add(int x, int y, int z)
{
	e[++ num].nxt = head[x];
	e[num].to = y;
	e[num].dis = z;
	head[x] = num;

	return ;
}

int main(void)
{
	/*
	freopen("std.in", r, stdin);
	freopen("std.out", w, stdout);
	//*/
	scanf("%d %d", &n, &m);
	for(int k = 1;k <= m;k ++)
	{
		scanf("%d %d %d", &x, &y, &z);
		add(x, y, z);
	}

	for(int k = 1;k <= n;k ++) dis[k] = INF;
	dis[1] = 0;

	for(int k = 1;k <= n;k ++)
	{
		u = -1, minn = INF;
		for(int j = 1;j <= n;j ++)
		if(!used[j] && dis[j]<minn)
		{
			u = j;
			minn = dis[j];
		}

		if(u==-1 || minn==INF) continue;
		used[u] = 1;

		for(int j = head[u];j;j = e[j].nxt)
		if(!used[e[j].to] && dis[e[j].to]>e[j].dis+dis[u])
			dis[e[j].to] = e[j].dis+dis[u];
	}

	for(int k = 1;k <= n;k ++) printf("%d ", dis[k]);

	system("pause");

	return 0;
}