#include<bits/stdc++.h>
using namespace std;
#define     Dbug1(x)                 cout << #x << " is " << x << endl;
#define     Dbug2(x,y)               cout << #x << " is " << x << "    " << #y << " is " << y << endl ;
#define     Dbug3(x,y,z)             cout << #x << " is " << x << "    " << #y << " is " << y << "    "<< #z << " is " << z << endl;
#define     Dbug4(x,y,z,a)           cout << #x << " is " << x << "    " << #y << " is " << y << "    "<< #z << " is " << z << "    " << #a << " is " << a << endl;
#define     Dbug5(x,y,z,a,b)         cout << #x << " is " << x << "    " << #y << " is " << y << "    "<< #z << " is " << z << "    " << #a << " is " << a << "    " << #b << " is " << b << endl;

///................................. point update range query..................................................
#define bucketNumber 1000000
int arr[1000000];
int BucketSize;///BucketSize = Bucketnumber
struct Bucket{
    int BucketSum;///initialize korle warning dekhai
    int Start,End;
}Bucket[bucketNumber];


void Build(int arr[],int n){
    for(int i=0,Bk=0;i<n;i+=BucketSize,Bk++){///bucket number is 0 indexed
        Bucket[Bk].Start=i;
        Bucket[Bk].End=i+BucketSize-1;
        Bucket[Bk].BucketSum=0;
        //Dbug2(Bucket[Bk].Start,Bucket[Bk].End);
    }Bucket[(n-1)/BucketSize].End=n-1;

    for(int i=0;i<n;i++){
        Bucket[i/BucketSize].BucketSum+=arr[i];
    }
}
void UpdatePoint(int pos,int val){///pos is 0 based
    if(val){
        arr[pos]+=val;
        Bucket[(pos)/BucketSize].BucketSum+=val;
    }
    else{
        Bucket[(pos)/BucketSize].BucketSum-=arr[pos];
        arr[pos]=0;
    }
}

int Query(int s,int e){///here s & e are 0 based
    int L_bucket,R_bucket;
    L_bucket=s/BucketSize;
    R_bucket=e/BucketSize;

    if(L_bucket==R_bucket){
        int sum=0;
        for(int i=s;i<=e;i++)
            sum+=arr[i];
        return sum;
    }
    else{
        int sum=0;
        for(int i=s;i<=Bucket[L_bucket].End;i++)
            sum+=arr[i];
        for(int i=L_bucket+1;i<R_bucket;i++)
            sum+=Bucket[i].BucketSum;
        for(int i=Bucket[R_bucket].Start;i<=e;i++)
            sum+=arr[i];
        return sum;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int tc,cs=1;cin>>tc;
    while(cs<=tc){
        int n,q;cin>>n>>q;

        for(int i=0;i<n;i++) scanf("%d",&arr[i]);

        BucketSize=sqrt(n)+1;

        Build(arr,n);

        printf("Case %d:\n",cs);
        while(q--){
//            for(int i=0;i<BucketSize;i++){
//                Dbug3(Bucket[i].BucketSum,Bucket[i].Start,Bucket[i].End)
//            }cout<<endl<<endl;

            int typ;scanf("%d",&typ);
            if(typ==1){
                int pos;scanf("%d",&pos);

                printf("%d\n",arr[pos]);
                UpdatePoint(pos,0);
            }
            else if(typ==2){
                int val,pos;scanf("%d%d",&pos,&val);
                UpdatePoint(pos,val);
            }
            else{
                int s,e;scanf("%d%d",&s,&e);
                printf("%d\n",Query(s,e));
            }
        }
        cs++;
    }
    return 0;
}


///.................................. Range update range query..........................................
#define bucketNumber 1000000
lli arr[1000000];
lli BucketSize;///BucketSize = Bucketnumber
struct Bucket{
    //int BucketSum;///initialize korle warning dekhai
    lli Sumition,SqureSum,lazy,AllVal;
    lli Start,End;
}Bucket[bucketNumber];


void Build(lli arr[],lli n){
    for(lli i=0,Bk=0;i<n;i+=BucketSize,Bk++){///bucket number is 0 indexed
        Bucket[Bk].Start=i;
        Bucket[Bk].End=i+BucketSize-1;
        Bucket[Bk].Sumition=0;
        Bucket[Bk].SqureSum=0;
        Bucket[Bk].lazy=0;
        Bucket[Bk].AllVal=inf;
        //Dbug2(Bucket[Bk].Start,Bucket[Bk].End);
    }Bucket[(n-1)/BucketSize].End=n-1;

    for(lli i=0;i<n;i++){
        Bucket[i/BucketSize].Sumition+=arr[i];
        Bucket[i/BucketSize].SqureSum+=(arr[i]*arr[i]);
    }
}
void Propagate(lli bucketNo){
    if(Bucket[bucketNo].lazy==0) return;
    for(lli i=Bucket[bucketNo].Start;i<=Bucket[bucketNo].End;i++){
        arr[i]+=Bucket[bucketNo].lazy;
    }
    Bucket[bucketNo].lazy=0;
}
void PropagateAllValue(lli bucketNo){
    if(Bucket[bucketNo].AllVal==inf) return;
    for(lli i=Bucket[bucketNo].Start;i<=Bucket[bucketNo].End;i++){
        arr[i]=Bucket[bucketNo].AllVal;
    }
    Bucket[bucketNo].AllVal=inf;
}
void RangeUpdate(lli s,lli e,lli val){///adding some value
    lli L_bucket,R_bucket;
    L_bucket=(s)/BucketSize;
    R_bucket=(e)/BucketSize;
    ///(a+v)^2=v*v*size +2v*(a+b+c+...)
    if(L_bucket==R_bucket){
        PropagateAllValue(L_bucket);
        lli Sm=0,SqSm=0;
        for(lli i=s;i<=e;i++){
            Sm+=arr[i];
            //SqSm+=(arr[i]*arr[i]);
            arr[i]+=val;
        }
        Bucket[L_bucket].SqureSum+=((val*val*(e-s+1))+(2*val*Sm));
        Bucket[L_bucket].Sumition+=(val*(e-s+1));
    }
    else{
        lli Sm=0;
        PropagateAllValue(L_bucket);
        for(lli i=s;i<=Bucket[L_bucket].End;i++){
            Sm+=arr[i];
            arr[i]+=val;
        }
        Bucket[L_bucket].SqureSum+=((val*val*(Bucket[L_bucket].End-s+1))+(2*val*Sm));
        Bucket[L_bucket].Sumition+=(val*(Bucket[L_bucket].End-s+1));

        for(lli i=L_bucket+1;i<R_bucket;i++){
            if(Bucket[i].AllVal==inf){
                Bucket[i].SqureSum+=((val*val*BucketSize)+(2*val*Bucket[i].Sumition));
                Bucket[i].Sumition+=(val*BucketSize);
                Bucket[i].lazy+=val;
            }
            else{
                Bucket[i].AllVal+=val;
                Bucket[i].SqureSum+=((val*val*BucketSize)+2*val+Bucket[i].Sumition);
                Bucket[i].Sumition+=(val*BucketSize);
            }
        }
        PropagateAllValue(R_bucket);
        Sm=0;
        for(lli i=Bucket[R_bucket].Start;i<=e;i++){
            Sm+=arr[i];
            arr[i]+=val;
        }
        Bucket[R_bucket].SqureSum+=((val*val*(e-Bucket[R_bucket].Start+1))+(2*val*Sm));
        Bucket[R_bucket].Sumition+=(val*(e-Bucket[R_bucket].Start+1));
    }

}

void RangeChange(lli s,lli e,lli NewVal){
    lli L_bucket,R_bucket;
    L_bucket=(s)/BucketSize;
    R_bucket=(e)/BucketSize;

    if(L_bucket==R_bucket){
        Propagate(L_bucket);
        lli Sm=0,Sqsm=0;
        for(lli i=s;i<=e;i++){
            Sm+=arr[i];
            Sqsm+=(arr[i]*arr[i]);
            arr[i]=NewVal;
        }
        Bucket[L_bucket].SqureSum-=Sqsm;
        Bucket[L_bucket].SqureSum+=(NewVal*NewVal*(e-s+1));
        Bucket[L_bucket].Sumition-=Sm;
        Bucket[L_bucket].Sumition+=(NewVal*(e-s+1));
    }
    else{
        Propagate(L_bucket);
        lli Sm=0,Sqsm=0;
        for(lli i=s;i<=Bucket[L_bucket].End;i++){
            Sm+=arr[i];
            Sqsm+=(arr[i]*arr[i]);
            arr[i]=NewVal;
        }
        Bucket[L_bucket].SqureSum-=Sqsm;
        Bucket[L_bucket].SqureSum+=(NewVal*NewVal*(Bucket[L_bucket].End-s+1));
        Bucket[L_bucket].Sumition-=Sm;
        Bucket[L_bucket].Sumition+=(NewVal*(Bucket[L_bucket].End-s+1));

        for(lli i=L_bucket+1;i<R_bucket;i++){
            Bucket[i].AllVal=NewVal;
            Bucket[i].SqureSum=(NewVal*NewVal*BucketSize);
            Bucket[i].Sumition=(NewVal*BucketSize);
            Bucket[i].lazy=0;
        }

        Propagate(R_bucket);
        Sm=0,Sqsm=0;
        for(lli i=Bucket[R_bucket].Start;i<=e;i++){
            Sm+=arr[i];
            Sqsm+=(arr[i]*arr[i]);
            arr[i]=NewVal;
        }
        Bucket[R_bucket].SqureSum-=Sqsm;
        Bucket[R_bucket].SqureSum+=(NewVal*NewVal*(e-Bucket[R_bucket].Start+1));
        Bucket[R_bucket].Sumition-=Sm;
        Bucket[R_bucket].Sumition+=(NewVal*(e-Bucket[R_bucket].Start+1));

    }
}
lli Query(lli s,lli e){
    lli L_bucket,R_bucket;
    L_bucket=(s)/BucketSize;
    R_bucket=(e)/BucketSize;

    lli ret=0;
    if(L_bucket==R_bucket){
        Propagate(L_bucket);
        PropagateAllValue(L_bucket);
        for(lli i=s;i<=e;i++){
            ret+=(arr[i]*arr[i]);
        }
    }
    else{
        Propagate(L_bucket);
        PropagateAllValue(L_bucket);
        for(lli i=s;i<=Bucket[L_bucket].End;i++){
            ret+=(arr[i]*arr[i]);
        }
        for(lli i=L_bucket+1;i<R_bucket;i++){
            ret+=Bucket[i].SqureSum;
        }
        Propagate(R_bucket);
        PropagateAllValue(R_bucket);
        for(lli i=Bucket[R_bucket].Start;i<=e;i++){
            ret+=(arr[i]*arr[i]);
        }
    }

    return ret;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    Case{
        lli n,q;scli2(n,q);
        for(lli i=0;i<n;i++) scli(arr[i]);
        BucketSize=sqrt(n)+1;

        Build(arr,n);
        printf("Case %d:\n",cs);
        while(q--){
            lli typ;scli(typ);
            if(typ==0){
                lli s,e,v;
                scli3(s,e,v);
                RangeChange(s-1,e-1,v);
            }
            else if(typ==1){
                lli s,e,v;
                scli3(s,e,v);
                RangeUpdate(s-1,e-1,v);
            }
            else{
                lli s,e;
                scli2(s,e);
                printf("%lld\n",Query(s-1,e-1));
            }
        }
    }

    return 0;
}


///////..................................Simple Range update range query....................
/// point update range query
#define bucketNumber 1000000
lli arr[1000000];
lli BucketSize;///BucketSize = Bucketnumber
struct Bucket{
    lli BucketSum,lazy;///initialize korle warning dekhai
    lli Start,End;
}Bucket[bucketNumber];


void Build(lli arr[],lli n){
    for(lli i=0,Bk=0;i<n;i+=BucketSize,Bk++){///bucket number is 0 indexed
        Bucket[Bk].Start=i;
        Bucket[Bk].End=i+BucketSize-1;
        Bucket[Bk].BucketSum=0;
        Bucket[Bk].lazy=0;
    }Bucket[(n-1)/BucketSize].End=n-1;
}
void Propagate(lli bucketNo){
    if(Bucket[bucketNo].lazy==0) return;
    for(lli i=Bucket[bucketNo].Start;i<=Bucket[bucketNo].End;i++){
        arr[i]+=Bucket[bucketNo].lazy;
    }
    Bucket[bucketNo].lazy=0;
}
void UpdateRange(lli s,lli e,lli val){///pos is 0 based
    lli L_bucket,R_bucket;
    L_bucket=s/BucketSize;
    R_bucket=e/BucketSize;

    if(L_bucket==R_bucket){
        Propagate(L_bucket);
        for(lli i=s;i<=e;i++){
            arr[i]+=val;
        }
        Bucket[L_bucket].BucketSum+=(val*(e-s+1));
    }
    else{
        Propagate(L_bucket);
        for(lli i=s;i<=Bucket[L_bucket].End;i++){
            arr[i]+=val;
        }
        Bucket[L_bucket].BucketSum+=(val*(Bucket[L_bucket].End-s+1));

        for(lli i=L_bucket+1;i<R_bucket;i++){
            Bucket[i].BucketSum+=(val*BucketSize);
            Bucket[i].lazy+=val;
        }

        Propagate(R_bucket);
        for(lli i=Bucket[R_bucket].Start;i<=e;i++){
            arr[i]+=val;
        }
        Bucket[R_bucket].BucketSum+=(val*(e-Bucket[R_bucket].Start+1));
    }
}

lli Query(lli s,lli e){///here s & e are 0 based
    lli L_bucket,R_bucket;
    L_bucket=s/BucketSize;
    R_bucket=e/BucketSize;

    if(L_bucket==R_bucket){
        Propagate(L_bucket);
        lli sum=0;
        for(lli i=s;i<=e;i++)
            sum+=arr[i];
        return sum;
    }
    else{
        lli sum=0;
        Propagate(L_bucket);
        for(lli i=s;i<=Bucket[L_bucket].End;i++)
            sum+=arr[i];
        for(lli i=L_bucket+1;i<R_bucket;i++)
            sum+=Bucket[i].BucketSum;
        Propagate(R_bucket);
        for(lli i=Bucket[R_bucket].Start;i<=e;i++)
            sum+=arr[i];
        return sum;
    }
}
