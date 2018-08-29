#include<bits/stdc++.h>

std :: map <std :: string, bool> hash;
std :: string s; 
int ans = 0;
int n;

int main(void)
{
	scanf("%d", &n);
	
	for(int k = 1;k <= n;k ++)
	{
		std :: cin >> s;
		if(!hash[s]) ans ++, hash[s] = 1;
	}
	
	printf("%d", ans);
	
	return 0;
}
