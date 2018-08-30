#include<cstdio>
typedef long long ll;

int n, q;
int num[1010000];
ll s[1010000] = {0};
ll f[1010000] = {0};
ll l, r;

int main(void)
{	
	freopen("var.in", "r", stdin);
	freopen("var.out", "w", stdout);
	
	scanf("%d %d", &n, &q);
	for(int k = 1;k <= n;k ++) scanf("%d", &num[k]);
	
	s[1] = num[1];
	for(int k = 2;k <= n;k ++)
		s[k] = s[k-1]+num[k];
	
	f[1] = num[1]*num[1];
	for(int k = 2;k <= n;k ++)
		f[k] = f[k-1]+num[k]*num[k];
	
	for(int k = 1;k <= q;k ++)
	{
		scanf("%lld %lld", &l, &r);
		if(l == r)
		{
			printf("0\n");
			continue;			
		}
		
		printf("%lld\n", ((f[r]-f[l-1])*(r-l+1)-(s[r]-s[l-1])*(s[r]-s[l-1])));
	}
	
	return 0;
}

//1 4 9 25
//1 5 14 39
