#include <bits/stdc++.h>
const int N = 1e8+1;

int n;
int ans;
bool f[N];

int main(void)
{
	scanf("%d", &n);
	
	int m = std :: sqrt(n);
	for(int k = 2;k <= m;k ++)
	if(! f[k])
	{
		for(int j = 2*k;j <= n;j += k)
		{
			if(f[j]) continue;
			
			f[j] = 1, ans ++;
		}
	}
	
	printf("%d", n-ans-1);
	
	return 0;
}
