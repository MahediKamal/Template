#include <bits/stdc++.h>
using namespace std;

char st1[1007];
char st2[1007];
int r;
int c;
int DP[1001][1001];

int LCS(){
    r=strlen(st1);
    c=strlen(st2);
    for(int i=0;i<=r;i++) DP[i][0]=0;
    for(int i=0;i<=c;i++) DP[0][i]=0;
    
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(st1[i-1]==st2[j-1])
                DP[i][j]=max(1+DP[i-1][j-1],max(DP[i][j-1],DP[i-1][j]));
            else
                DP[i][j]=max(DP[i][j-1],DP[i-1][j]);
            cout<<DP[i][j]<<" ";
        }cout<<endl;
    }
    return DP[r][c];
}

void printLCS(int i,int j){
    if(i==0 || j==0) return;
    if(DP[i][j]==DP[i-1][j]) printLCS(i-1,j);
    else if(DP[i][j]==DP[i][j-1]) printLCS(i,j-1);
    else if(DP[i][j]==1+DP[i-1][j-1]){
        printLCS(i-1,j-1);
        cout<<st1[i-1];
    } 
    
}
int main()
{
    scanf("%s%s",st1,st2);
    cout<<LCS()<<endl;
    printLCS(r,c);
    return 0;
}
