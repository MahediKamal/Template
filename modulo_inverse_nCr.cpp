include<bits/stdc++.h>//as fermat's little theorm is use , mod must be a prime num
using namespace std;
#define lli long long int
#define mod 1000000007
lli fct_mod_inv[1000007];
lli fact[2000009];
lli bin_exp(lli bs,lli pow){
    lli res=1;
    while(pow){
        if(pow%2==1){
            res=res*bs;
            res=res%mod;
        }
        bs=bs*bs;
        bs=bs%mod;
        pow=pow/2;
    }
    return res;
}

int main()
{
    fact[0]=1;
    for(lli i=1;i<2000002;i++){
        fact[i]=fact[i-1]*i;
        fact[i]%=mod;
    }

    fct_mod_inv[0]=fct_mod_inv[1]=1;
    for(lli i=2;i<1000001;i++){
        fct_mod_inv[i]=(fct_mod_inv[i-1]*bin_exp(i,mod-2))%mod;
    }
    lli t,cs=1;
    cin>>t;
    while(cs<=t){
        lli n,k;
        cin>>n>>k;
        //n+k-1 C k-1
        lli nn=n+k-1,rr=k-1;
        lli ans=(fact[nn]*fct_mod_inv[nn-rr])%mod;
        ans=(ans*fct_mod_inv[rr])%mod;
        printf("Case %lld: %lld\n",cs,ans);
        cs++;
    }


    return 0;
}
