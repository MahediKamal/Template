/*
given n jobs and their starting(t1) and ending(t2) time and profit(p) for each n jobs.
find the maximum profit you can make as you might not be able to do all jobs as
their time overlaps .
*/
/*
input -
   n=4
   t1  t2  p
   2   3   4
   4   7   6
   6   8   5
   8   9   4
*/

int max_profit(int t1[],int t2[],int p[],int n){
    int * pp=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        pp[i]=p[i];
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(t1[i]>=t2[j]){
                if(pp[i]<(p[i]+pp[j])){
                    pp[i]=p[i]+pp[j];
                }
            }
        }
    }
    int mx_p=0;
    for(int i=0;i<n;i++){
        if(pp[i]>mx_p)
            mx_p=pp[i];
    }
    return mx_p;

}
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int *t1=(int *)malloc(sizeof(int)*n);
    int *t2=(int *)malloc(sizeof(int)*n);
    int *p=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&t1[i],&t2[i],&p[i]);
    }
    //srt_accordint_to_t2(t1,t2,p);//I havent done it here , bt it is essential.
    int profit=max_profit(t1,t2,p,n);
    printf("%d",profit);
    return 0;
}


