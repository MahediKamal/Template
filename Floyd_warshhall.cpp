#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mx 200 // mx is the number of nodes
#define inf 1<<30 // inf + inf > int, so we should use long here



lli d[mx][mx]; // graph
int v_nm, e_nm;

void init(){
    for(int i=0; i<mx-1; i++){
        for(int j=0; j<mx-1; j++){
            d[i][j] = inf;
        }
    }
}

void floyd_warshall(){ // all pair shortest path, 0 based operation
    for (int k = 0; k < v_nm; ++k) {
        for (int i = 0; i < v_nm; ++i) {
            for (int j = 0; j < v_nm; ++j) {
                if (d[i][k] < inf && d[k][j] < inf){ // needed for negative edge
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]); // normal
                }
            }
        }
    }
}
