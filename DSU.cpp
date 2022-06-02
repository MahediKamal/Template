#include<bits/stdc++.h>
using namespace std;
#define sz 1000007

int n;
int par[sz];
int Size[sz];
void init(){
    for(int i=0;i<=n;i++){
        par[i]=i;Size[i]=1;
    }
}
int Parent(int i){
    if(par[i]==i) return i;
    return par[i]=Parent(par[i]);
}
void Union(int i,int j){
    i=Parent(i);j=Parent(j);
    if(Size[i]<Size[j]) swap(i,j);
    par[j]=i;
    Size[i]+=Size[j];
}
int main()
{


    return 0;
}
