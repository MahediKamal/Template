//////////////////////////////////////////////////////////////Simple LCA ////////////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;
#define sz 100000
#define maxP 20//log2(sz)+1=18;
///         1
///        / \   (input test graph)
///       2   5
///      / \   \
///     3   8   6
///    /   /   / \
///   4   9   10  7
///        \
///        11

int Lvl[sz];
vector<int>graph[sz];
int Parent[sz][maxP];
int MaxPow;
int n;

int chk(int num,int pos){return num & (1<<(pos));}

void DFS(int src,int par,int L){///nodes are from 1 to n
    Lvl[src]=L;
    Parent[src][0]=par;
    for(int i=0;i<graph[src].size();i++){
        int  adj=graph[src][i];
        if(adj!=par)
            DFS(adj,src,L+1);
    }
}
void Build(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=MaxPow;j++){
            Parent[i][j]=-1;
        }
    }
    DFS(1,-1,0);

    for(int j=1;j<=MaxPow;j++){
        for(int i=1;i<=n;i++){///nodes are from 1 to n
            if(Parent[i][j-1]!=-1)
                Parent[i][j]=Parent[Parent[i][j-1]][j-1];///j th parent of i
            //else
            //    Parent[i][j]=-1;
        }
    }
}

int LCA(int u,int v){
    if(Lvl[u]<Lvl[v]) swap(u,v);
    int lift=Lvl[u]-Lvl[v];
    for(int i=0;i<=MaxPow;i++){
        if(chk(lift,i))
            u=Parent[u][i];
    }
    if(u==v) return v;
    for(int i=MaxPow;i>=0;i--){
        if(Parent[u][i]!=Parent[v][i]){
            u=Parent[u][i];
            v=Parent[v][i];
        }
    }
    return Parent[u][0];
}

int main()
{
    freopen("input.txt","r",stdin);
    cin>>n;
    MaxPow=log2(n)+1;

    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    Build();
    for(int i=1;i<=n;i++)
        cout<<i<<"->"<<Lvl[i]<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=MaxPow;j++){
            cout<<Parent[i][j]<<" ";
        }cout<<endl;
    }
    cout<<"*****LCA = "<<LCA(4,1);
    return 0;
}




////////////////////////////////////////  With Function and Values are on the edge //////////////////////////////////////


#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL);
#define     Dbug1(x)                 cout << #x << " is " << x << endl;
#define     Dbug2(x,y)               cout << #x << " is " << x << "    " << #y << " is " << y << endl ;
#define     Dbug3(x,y,z)             cout << #x << " is " << x << "    " << #y << " is " << y << "    "<< #z << " is " << z << endl;
#define     Dbug4(x,y,z,a)           cout << #x << " is " << x << "    " << #y << " is " << y << "    "<< #z << " is " << z << "    " << #a << " is " << a << endl;
#define     Dbug5(x,y,z,a,b)         cout << #x << " is " << x << "    " << #y << " is " << y << "    "<< #z << " is " << z << "    " << #a << " is " << a << "    " << #b << " is " << b << endl;
#define visited 1
#define pi acos(-1)
#define pbk push_back
#define inf 1<<30
#define lli long long int
#define sci(a) scanf("%d",&a)
#define sci2(a,b) sci(a);sci(b)
#define sci3(a,b,c) sci(a);sci(b);sci(c)
#define scli(a) scanf("%lld",&a)
#define scli2(a,b) scli(a);scli(b)
#define scli3(a,b,c) scli(a);scli(b);scli(c)
#define mod 100000007
#define Case int t,cs=0;scanf("%d",&t);while(++cs<=t)
void sciar(int a[],int n){for(int i=0;i<n;i++)scanf("%d",&a[i]);}

#include<bits/stdc++.h>
using namespace std;
#define sz 200002
#define maxP 19//log2(sz)+1=18;
///         1
///        / \   (input test graph)
///       2   5
///      / \   \
///     3   8   6
///    /   /   / \
///   4   9   10  7
///        \
///        11

int Lvl[sz];
vector< pair<int,int> >graph[sz];
int Parent[sz][maxP];
int Val1[sz][maxP];
int Val2[sz][maxP];
int MaxPow;
int n;

int chk(int num,int pos){return num & (1<<(pos));}
int func1(int n1,int n2){return max(n1,n2);}
int func2(int n1,int n2){return min(n1,n2);}

void DFS(int src,int par,int L){///nodes are from 1 to n
    Lvl[src]=L;
    Parent[src][0]=par;
    for(int i=0;i<graph[src].size();i++){
        pair<int,int>  pr=graph[src][i];
        int adj=pr.first;
        if(adj!=par){
            Val1[adj][0]=pr.second;
            Val2[adj][0]=pr.second;
            DFS(adj,src,L+1);
        }
    }
}
void Build(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=MaxPow;j++){
            Parent[i][j]=-1;
            Val1[i][j]=-1;
            Val2[i][j]=inf;
        }
    }
    DFS(1,-1,0);

    for(int j=1;j<=MaxPow;j++){
        for(int i=1;i<=n;i++){///nodes are from 1 to n
            if(Parent[i][j-1]!=-1){
                Parent[i][j]=Parent[Parent[i][j-1]][j-1];///j th parent of i
                Val1[i][j]=func1(Val1[i][j-1],Val1[Parent[i][j-1]][j-1]);
                Val2[i][j]=func2(Val2[i][j-1],Val2[Parent[i][j-1]][j-1]);
            }
            //else
            //    Parent[i][j]=-1;
        }
    }
}

int LCA(int u,int v){
    if(Lvl[u]<Lvl[v]) swap(u,v);
    int lift=Lvl[u]-Lvl[v];
    for(int i=0;i<=MaxPow;i++){
        if(chk(lift,i))
            u=Parent[u][i];
    }
    if(u==v) return v;
    for(int i=MaxPow;i>=0;i--){
        if(Parent[u][i]!=Parent[v][i]){
            u=Parent[u][i];
            v=Parent[v][i];
        }
    }
    return Parent[u][0];
}
pair<int,int> Query(int u,int v,int A){
    int lift=Lvl[u]-Lvl[A];
    int res1=-1,res2=inf;
    for(int i=MaxPow;i>=0;i--){
        if(chk(lift,i)){
            res1=max(res1,Val1[u][i]);
            res2=min(res2,Val2[u][i]);
            u=Parent[u][i];
        }
    }
    lift=Lvl[v]-Lvl[A];
    for(int i=MaxPow;i>=0;i--){
        if(chk(lift,i)){
            res1=max(res1,Val1[v][i]);
            res2=min(res2,Val2[v][i]);
            v=Parent[v][i];
        }
    }
    pair<int,int> pr=make_pair(res1,res2);
    return pr;
}
int main()
{
    //freopen("input.txt","r",stdin);
    Case{
        sci(n);
        for(int i=1;i<n;i++){
            int u,v,w;sci3(u,v,w);
            graph[u].pbk(make_pair(v,w));
            graph[v].pbk(make_pair(u,w));
        }
        MaxPow=log2(n)+1;
        Build();


        int q;sci(q);
        printf("Case %d:\n",cs);
        while(q--){
            int u,v;sci2(u,v);
            int A=LCA(u,v);
            //Dbug1(A);
            pair<int,int> ans=Query(u,v,A);
            printf("%d %d\n",ans.second,ans.first);
        }

        for(int i=0;i<=n;i++)
            graph[i].clear();
    }
    return 0;
}
