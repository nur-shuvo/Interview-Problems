#include<bits/stdc++.h>
using namespace std;
#define Max 1000000
char  prime[Max+1];
void sieve()
{
    int i,j,x;
    for(i=0;i<=Max;i++)
        prime[i]=0;
    prime[0]=prime[1]=1;
    for(i=4;i<=Max;i+=2)
        prime[i]=1;
    x = sqrt(Max);
    for(i=3; i<=x; i+=2){
        for(j=i*i;j<=Max;j+=i)
            prime[j]=1;
    }
}
int main()
{
    sieve();
    int i;
    for(i=0 ; i <= 100; i++){
        if(prime[i] ==0)  /* 0 for prime */
        printf("%d\t is prime .\n", i);
    }
    return 0;
}
