#include<bits/stdc++.h>

struct node
{
	int x, y;
	int w;
	int num;
}a[1000100];
int num = 0, p = 0, q = 0;
int bx, by, ex, ey;
int n, m;
node oplist[1000100];
node cllist[1000100];
bool op[1000100];
bool cl[1000100];
int begin, end;

int main(void)
{
	scanf("%d %d", &n, &m);
	scanf("%d %d %d %d", &bx, &by, &ex, &ey);
	
	for(int k = 1;k <= n;k ++)
		for(int j = 1;j <= m;j ++)
		{
			a[++ num].x = k;
			a[num].y = j;
			a[num].num = num;
			
			scanf("%d", &a[num].w);
			
			if(k == bx && j == by) begin = num;
			if(k == ex && j == ey) end = num;
		}
	
	oplist[++ p] = a[begin];
	op[a[begin].num] = 1;
	
	do 
	{
		;
	}while(op[a[end].num]);
	
	return 0;
}
