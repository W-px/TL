#include<bits/stdc++.h>
typedef long long ll;

ll b, p, q;

ll quick_pow(ll x)
{
	if(x == 0) return 1;
	
	ll tmp = quick_pow(x/2);
	
	if(x&1)
		return tmp*tmp*b%q;
	else
		return tmp*tmp%q;
}

int main(void)
{
	scanf("%lld %lld %lld", &b, &p, &q);
	
	printf("%lld^%lld mod %lld=%lld", b, p, q, quick_pow(p)%q);
	
	return 0;
}
