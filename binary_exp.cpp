#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mod 1000000007
lli bin_exp(lli bs,lli pow){
    lli res=1;
    while(pow){
        if(pow%2==1){
            pow--;
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
    cout<<bin_exp(2,13);

    return 0;
}
