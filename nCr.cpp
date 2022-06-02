
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mod 1000000007
lli lim=1020;
lli nCr[1020][1020];
int main()
{
    for(int i=0;i<lim;i++){
        nCr[i][0]=nCr[i][i]=1;
        for(int j=1;j<i;j++){
            nCr[i][j]=nCr[i-1][j]+nCr[i-1][j-1];
            nCr[i][j]=nCr[i][j]%mod;
        }
    }
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%lld",nCr[n+2*m-1][2*m]);//nCr[n][r]

    return 0;
}
