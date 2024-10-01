#include<bits/stdc++.h>
using namespace std;

int n,K;
const int MAX=11;

int visited[2*MAX+1];
int x[2*MAX+1];
int d[2*MAX+1][2*MAX+1];

int load = 0;
int f=0, f_MIN=INT_MAX, Cmin=INT_MAX;

void updateDistance(){
    for(int i = 0; i <= 2*n; i++)
        for(int j = 0; j <= 2*n; j++)
            cin >> d[i][j];
}

bool check(int v, int k){
    if(visited[v]) return false;
    if(v > n){
        if(!visited[v-n]) return false;
    }else{
        if( load + 1 > K ) return false;
    }
    return true;
}

void updateBest(){
    if(f + d[x[2*n]][0] < f_MIN){
        f_MIN = f + d[x[2*n]][0];
    }
}

void TRY(int k){
    for(int v = 1; v <= 2*n; v++){
        if(check(v,k)){ 
            x[k]=v;
            f += d[x[k-1]][x[k]];
            visited[v] = true;
            load += (v <= n ? 1 : -1);
            if( k == 2*n ) updateBest();
            else{
                if(f + Cmin * (2*n+1-k) < f_MIN) 
                    TRY(k+1);
            }
            load += (v <= n ? -1 : 1);
            f = f - d[x[k-1]][x[k]];
            visited[v] = false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> K ;

    x[0]=0;
    updateDistance();

    for(int i = 0; i <= 2*n; i++)
        for(int j = 0; j <= 2*n; j++)
            if(d[i][j] < Cmin && j != i) Cmin = d[i][j];
            
    TRY(1);
    cout << f_MIN ; 
    return 0;
}
