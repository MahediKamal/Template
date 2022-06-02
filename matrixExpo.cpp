#include<bits/stdc++.h>
using namespace std;
#define sz 100
#define lli long long int
lli mod=10;
lli Mtrx[sz][sz];
lli Idnt[sz][sz];
lli dimension=2;

void mul(lli M[][sz],lli row1,lli col1,lli N[][sz],lli col2){
    /// if col1!=ror2 - impossible
    lli tmp[row1+1][col2+1];
    for(lli i=0;i<row1;i++){
        for(lli j=0;j<col2;j++){
            lli x=0;
            for(lli k=0;k<col1;k++){
                x+=(M[i][k]*N[k][j])%mod;
               // x=x%mod;
            }
            tmp[i][j]=x%mod;
        }
    }

    for(lli i=0;i<row1;i++){
        for(lli j=0;j<col2;j++){
            N[i][j]=tmp[i][j];///this is always not possible for different dimentional matrix
        }
    }
}

void MtrxExpo(lli M[][sz],lli pow){
    if(pow<=0) return;
     for(lli i=0;i<dimension;i++){
        for(lli j=0;j<dimension;j++){
            if(i==j) Idnt[i][j]=1;
            else Idnt[i][j]=0;
        }
    }

    while(pow){
        if(pow%2==1){
            pow--;
            mul(M,dimension,dimension,Idnt,dimension);
        }
        mul(M,dimension,dimension,M,dimension);
        pow=pow/2;
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    lli t,cs=1;cin>>t;
    while(cs<=t){
        lli a,b,n,m;
        scanf("%lld%lld%lld%lld",&a,&b,&n,&m);
        mod=10;
        for(lli i=1;i<m;i++) mod*=10;

        Mtrx[0][0]=1;Mtrx[1][0]=1;Mtrx[0][1]=1;Mtrx[1][1]=0;

        MtrxExpo(Mtrx,n-1);

        lli X[sz][sz];
        X[0][0]=b;X[1][0]=a;
        if(n>=2)
            mul(Idnt,2,2,X,1);
        else{
            if(n==0) X[0][0]=a;
            else X[0][0]=b;
        }
        printf("Case %lld: %lld\n",cs,X[0][0]%10);
        cs++;
    }
    return 0;
}
