#include<bits/stdc++.h>
using namespace std;

//////////////////////////////technique 1 , till=largest num

int chk[10000000];
void seive(int till){
    int x=sqrt(till);
    for(int i=3;i<=x;i+=2){
        if(chk[i-1]>0) continue;
        for(int j=i*i;j<=till;j+=i){
            if(chk[j-1]==0)
                chk[j-1]=i;//saving lowest prime divisor of a composite num
        }
    }

}
vector<int>PrmFactor;
void primeFactorization(int num){//ai way ta prime factorization korle seive a till=num hobe  bt prime ar vectro ra create kora lagbe na
    while(num>1){
        if(chk[num-1]==0 && num%2!=0){
            PrmFactor.push_back(num);
            break;
        }
        int div;
        if(num%2==0)
            div=2;
        else
            div=chk[num-1];

        PrmFactor.push_back(div);
        num=num/div;
    }
}



//////////////////////////////technique 2 till=sqrt(num)

#define Size 100005
bool chk[Size];
vector<int>prime;
void seive(int till){
    int x=sqrt(till);
    for(int i=3;i<=x;i+=2){
        if(chk[i-1]==true) continue;
        for(int j=i*i;j<=till;j+=i){
            chk[j-1]=true;
        }
    }
    prime.push_back(2);
    for(int i=3;i<=till;i+=2){
        if(chk[i-1]!=true)
            prime.push_back(i);
    }

}


int  PrmFactorixation(int num){
    vector<int>prmFactor;
    int pos=0;
    while(num>1 && pos<prime.size()){
        if(num<Size && chk[num-1]==0 && num%2!=0){
            prmFactor.push_back(num);
            num/=num;
            break;
        }
        while(num%prime[pos]==0){
            num=num/prime[pos];
            prmFactor.push_back(prime[pos]);
        }
        pos++;
    }
    if(num>1)
        prmFactor.push_back(num);
    ///NOD
    int pw=0,fact=-1;
    int nod=1;
    for(int i=0;i<prmFactor.size();i++){
        if(prmFactor[i]==fact){
            pw++;
        }
        else{
            nod*=(pw+1);
            fact=prmFactor[i];
            pw=1;
        }
    }
    nod*=(pw+1);
    return nod;
}


