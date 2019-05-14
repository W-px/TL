#include <bits/stdc++.h>

const int MAX = 10000;

int n;
int a[MAX];
int s[MAX], e[MAX], sum[MAX];
int dis, num;
int T;
int ans;

int main(void)
{
    scanf("%d", &n);
    for(int k = 1;k <= n;k ++) scanf("%d", &a[k]);

    num = dis = std :: sqrt(n);
    
    //Saving
    int u = 1, v = 1;
    for(int k = 1;k <= num*dis;k ++)
    {
        if(k%num == 1) s[u ++] = k;
        if(!k%num) e[v ++] = k;

        if(k%num != 0) sum[k/dis+1] += a[k];
            else sum[k/dis] += a[k];
    }
    for(int k = num*dis+1;k <= n;k ++) sum[num+1] += a[k];

    scanf("%d", &T);
    while(T --)
    {
        ans = 0;

        int p, q;
        scanf("%d %d", &p, &q);

        int st = p/dis;
        int ed = q/dis;
        ed += ((q%dis) != 0);

        for(int k = st;k <= ed;k ++) ans += sum[k];
    //    printf("Before the WORK %d\n", ans);
        for(int k = dis*(st-1)+1;k < p;k ++) ans -= a[k];
        for(int k = dis*ed;k > q;k --) ans -= a[k];

        printf("The sum is %d\n", ans);
    }

    return 0;
}