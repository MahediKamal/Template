// possible parenthesize = 2nCn / (n+1)

#include <bits/stdc++.h>
using namespace std;
#define inf 1<<30

int DP[1001][1001];
int P[1001][1001];
vector< pair<int,int> >matrix;
int n;


int cost(int s,int e){
    cout<<s+1<<" "<<e+1<<endl;
    int res=inf;
    for(int i=s;i<e;i++){
        int r=DP[s][i]+DP[i+1][e]+matrix[s].first*matrix[i].second*matrix[e].second;
        if(r<res) P[s][e]=i;
        res=min(res,r);
    }
    return res;
}
int solve(){
    for(int i=0;i<=n;i++){
        DP[i][i]=0;P[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j+i<n;j++){
            DP[j][j+i]=cost(j,j+i);
        }
    }
    return DP[n][n];
}

void Parenthesize(int i,int j){
    int point=P[i][j];
    if(i==j){
        cout<<"("<<i<<")";
        return;
    }
    cout<<"(";
    Parenthesize(i,point);
    Parenthesize(point+1,j);
    cout<<")";
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        int r,c;
        cin>>r>>c;
        matrix.push_back(make_pair(r,c));
    }
    solve();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<DP[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<P[i][j]<<" ";
        cout<<endl;
    }

    Parenthesize(0,n-1);
    return 0;
}
