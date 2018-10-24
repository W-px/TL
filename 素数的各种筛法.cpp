#include<bits/stdc++.h>
typedef long long ll;
const long long N = 1e10;
const long long MAX = 1e7;

ll n;
int u;
bool f[N];
int t1, t2, st;
int prime[MAX], v[MAX];

void prime1(void)
{	
	for(int k = 2;k <= n;k ++)
	if(! f[k])
	{
		for(int j = 2;j <= n/k;j ++)
			f[k*j] = 1;
	}
	
	return ;
}

void prime2(void)
{
	int u = 0;
	
	for(int k = 2;k <= n;k ++)
	{
		if(v[k] == 0) v[k] = k, prime[++ u] = k;
		
		for(int j = 1;j <= u;j ++)
		{
			if(prime[j]>v[k] || prime[j]>n/k) break;
			
			v[k*prime[j]] = prime[j];			
		}
	}
	
	return ;
}

/*
Author: bellman_ford (W_px)
time: 2018/10/24/13:10
普通Eratosthenes筛法和线性筛法的时间复杂度比较 
*/

int main(void)
{
	scanf("%lld", &n);
	
	st = clock();
	
	prime1();
	t1 = clock();
	
	prime2();
	t2 = clock();
	
	printf("Prime1: %d\nPrime2: %d", t1-st, t2-t1);
	
	return 0;
}
