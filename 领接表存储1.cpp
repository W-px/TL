#include<bits/stdc++.h>
#define MAXM 10001
typedef long long ll;

ll n, m;
struct edge
{
	ll nxt, to;
	ll dis;
}e[MAXM];
ll head[MAXM], num = 0;

void add(ll u, ll v, ll dis)
{
	e[++ num].nxt = head[u];
	e[num].to = v;
	e[num].dis = dis;
	
	head[u] = num;
}

int main(void)
{
	scanf("%lld %lld", &n, &m);
	for(int k = 1;k <= m;k ++)
	{
		ll x, y, z;
		scanf("%lld %lld %lld", x, y, z);
		
		add(x, y, z);
	}
	
	return 0;
}
