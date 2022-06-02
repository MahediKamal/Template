#include<bits/stdc++.h>
using namespace std;

bool chk[10000000];
vector<int>prime;
void seive(int till){
    int x=sqrt(till);
    for(int i=3;i<=x;i+=2){
        if(chk[i-1]==true) continue;
        for(int j=i*i;j<=till;j+=i+i){
            chk[j-1]=true;
        }
    }
    prime.push_back(2);
    for(int i=3;i<=till;i+=2){
        if(chk[i-1]!=true)
            prime.push_back(i);
    }

}

int main()
{
    seive(31);
    for(int i=0;i<prime.size();i++)
        cout<<prime[i]<<" ";


    return 0;
}
