#include<bits/stdc++.h>
using namespace std;

const int MAX_tea = 11,MAX_sub = 31;
int m,n,res;
vector<int> sub[MAX_sub];
bool conflict[MAX_sub][MAX_sub];
int x[MAX_sub];
int load[MAX_tea];

void input(){
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        int k; cin >> k;
        for(int j = 1; j <= k; j++){
            int c; cin >> c;
            sub[c].push_back(i);
        }
    }
    int K; cin >> K;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j ++){
            conflict[i][j]=false;
        }
    }
    for(int k = 1; k <= K; k++){
        int i,j; cin >> i >> j;
        conflict[i][j] = true; conflict[j][i] = true;
    }
}

void solution(){
    int maxLoad = 0;
    for(int t = 1; t <= m; t++){
        maxLoad = max(maxLoad, load[t]);
    }
    if(maxLoad < res) res = maxLoad;
}


bool  check(int t, int k){
    for(int i = 1; i <= k-1; i++){
        if(conflict[i][k] && x[i] == t) return false;
    }
    return  true;
}

void TRY(int k){
    for(int i = 0; i < sub[k].size(); i++){
        int t = sub[k][i];
        if(check(t,k)){
            x[k] = t;
            load[t] +=1;
            if(k==n) solution();
            else{
                if(load[t] < res) TRY(k+1);
            }
            load[t] -= 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio;
    cin.tie(NULL);cout.tie(NULL);
    input();
    for(int t = 1; t <= m; t++) load[t] = 0;
    res = 1e9;
    TRY(1);
    cout << res;

    return 0;
}