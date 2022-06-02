/*
given different values of n coins and total T . how many ways you can
get the total by combining the coins.(every number of coin is infinity )
*/
/*
input-t=5 ,n=3
    5
    3
    1 2 3

output- 5
*/
#include<stdio.h>
#include<stdlib.h>
int combination_coin(int arr[],int n,int T){
    int count[n+1][T+1];
    for(int i=0;i<=T;i++)
        count[0][i]=0;
    for(int i=0;i<=n;i++)
        count[i][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=T;j++){
            if(arr[i-1]<=j){
                count[i][j]=count[i-1][j]+count[i][j-arr[i-1]];
            }else{
                count[i][j]=count[i-1][j];
            }
            //printf("%d ",count[i][j]);
        }
        //printf("\n");
    }
    return count[n][T];
}

int main()
{
    int T,n;
    scanf("%d %d",&T,&n);
    int *arr=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int total_comb=combination_coin(arr,n,T);
    printf("%d",total_comb);
    return 0;
}
