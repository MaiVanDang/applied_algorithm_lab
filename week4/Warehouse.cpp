#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e3 + 2;
int N,T,D;
int a[MAX];
int t[MAX];
int f[MAX][206];
int res;

void input(){
    cin >> N >> T >> D;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= N; i++){
        cin >> t[i];
    }
}

void solve(){
    for(int i = 1; i <= N; i++){
        for(int k = t[i]; k <= T; k++){
            for(int j = max(0,i-D); j <= i-1; j++){
                f[i][k] = max(f[i][k], f[j][k - t[i]] + a[i]);
            }
            res = max(res,f[i][k]);
        }
    }
    cout << res << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}