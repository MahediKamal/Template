/*
 n element each having m(m=0>) weight and v value (one quantity of each item ).
 you can gather maximum x weight .what is the maximum value you can achieve ?
*/
/*
input -(x=7,n=4)
    7
    4
    1 1
    3 4
    4 5
    5 7
*/
#include<stdio.h>
int get_max(int m[],int v[],int n,int x){
    int arr[n+1][x+1];
    for(int i=0;i<=n;i++){
        arr[i][0]=0;
    }
    for(int i=0;i<=x;i++){
        arr[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(m[i-1]<=j){
                if((v[i-1]+arr[i-1][j-m[i-1]])>arr[i-1][j]){
                    arr[i][j]=v[i-1]+arr[i-1][j-m[i-1]];
                }else{
                    arr[i][j]=arr[i-1][j];
                }
            }
            else{
                arr[i][j]=arr[i-1][j];
            }
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    int max_val=arr[n][x];
    printf("%d\n",arr[n][x]);
    return max_val;
}

int main()
{
    int n,x;
    scanf("%d %d",&x,&n);
    int m[n],v[n];
    for(int i=0;i<n;i++){
        scanf("%d  %d",&m[i],&v[i]);
    }

    int val=get_max(m,v,n,x);
    printf("%d",val);
    return 0;
}
