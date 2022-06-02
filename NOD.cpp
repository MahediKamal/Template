#include<stdio.h>
#include<math.h>

int arr[1000000];
int prm[100000];
void primenum(){
    //fac[0][0]=1;
    int l=sqrt(1000000);
    int i,j;
    arr[0]=1;
    for(i=4;i<=1000000;i=i+2){
        arr[i-1]=1;
    }
    for(i=3;i<=l;i=i+2){
        if(arr[i-1]==1){continue;}
        for(j=i;j*i<=1000000;j=j+2){
            arr[j*i-1]=1;
        }
    }
    j=0;
    for(i=0;i<1000000;i++){
        if(arr[i]==0){
            prm[j]=i+1;
            j++;
        }
    }
}


int NOD(int n){
    int res=1,i;
    int sqr=sqrt(n);
    for(i=0;prm[i]<=sqr && prm[i]!=0;i++){
        /*if(arr[n-1]==1){
            break; //ata use korle for ar condition lagbe na
        }*/
        if(n%prm[i]==0){
            int x=0;
            while(n%prm[i]==0){
                n=n/prm[i];
                x++;
            }
            res=res*(x+1);
            sqr=sqrt(n);
        }
    }
    if(n!=1){
        res=res*2;
    }
    return res;

}
int main(){
    primenum();
    int n;
    scanf("%d",&n);
    printf("%d",NOD(n));

    return 0;
}
