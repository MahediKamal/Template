#include<bits/stdc++.h>
using namespace std;

int arr[30007];
int BucketSize;
int frq[1000007];
int Query[200003];
int ans=0;
struct Data {
    int Start,End,QueryNum,BucketNum;
    Data(int a,int b,int c){
        Start=a;
        End=b;
        QueryNum=c;
        BucketNum=Start/BucketSize;
    }
    bool operator < ( const Data& b ) const {
        if( BucketNum == b.BucketNum ) {
            if(BucketNum%2==0)
                return End < b.End;
            else
                return End > b.End;
        }else return Start < b.Start; //smallest age chaile >
    }
};
vector<Data>Q;

void Add(int i){
    frq[arr[i]]++;
    if(frq[arr[i]]==1)
        ans++;
}
void Remove(int i){
    frq[arr[i]]--;
    if(frq[arr[i]]==0)
        ans--;
}
void Mos(){
    sort(Q.begin(),Q.end());
    ans=1;
    int l=1,r=1;
    frq[arr[1]]++;
    for(int i=0;i<Q.size();i++){
        int s=Q[i].Start;
        int e=Q[i].End;
        while(l<s){
            Remove(l);l++;
        }
        while(l>s){
            l--;Add(l);
        }
        while(r<e){
            r++;Add(r);
        }
        while(r>e){
            Remove(r);r--;
        }
        Query[Q[i].QueryNum]=ans;
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    int n;
    scanf("%d",&n);
    BucketSize=sqrt(n)+1;
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int s,e;
        scanf("%d%d",&s,&e);
        Q.push_back(Data(s,e,i));
    }

    Mos();

    for(int i=1;i<=q;i++){
        printf("%d\n",Query[i]);
    }
    return 0;
}
