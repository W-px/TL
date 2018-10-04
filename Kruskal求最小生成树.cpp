#include<bits/stdc++.h>
const int M = 200100;
const int N = 5100;

struct edge
{
	int u, v;
	int dis;
}e[M];
int n, m;
int f[N];
int cnt = 0, sum = 0;

int find(int x)
{
	if(f[x] == x) return f[x];
	
	f[x] = find(f[x]);
	return f[x];
}

void unin(int x, int y)
{
	int xx = find(x), yy = find(y);
	
	if(xx != yy) f[yy] = xx;
	return ;
}

bool cmp(edge x, edge y)
{
	return x.dis < y.dis;
}

int main(void)
{	
	scanf("%d %d", &n, &m);
	for(int k = 1;k <= m;k ++)
		scanf("%d %d %d", &e[k].u, &e[k].v, &e[k].dis);	
	
	std :: sort(e+1, e+m+1, cmp);
	
	for(int k = 1;k <= n;k ++) f[k] = k;
	for(int k = 1;k <= m;k ++)
	{
		if(find(e[k].u) != find(e[k].v))
		{
			unin(e[k].u, e[k].v);
			
			cnt ++;
			sum += e[k].dis;
		}
		
		if(cnt == n-1)
		{
			printf("%d", sum);
			return 0;
		}
	}
	
	printf("orz");
	
	return 0;
}
