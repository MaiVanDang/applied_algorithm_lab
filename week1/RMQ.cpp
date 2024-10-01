#include<bits/stdc++.h>
using namespace std;

int n;
int a[1000000];
int M[20][1000000];

void preprocessing(){
    for(int i = 0; (1<<i) < n; i++)
        for(int j = 0; j < n; j++)
            M[i][j]=-1;
    
    for(int i=0; i<n; i++) M[0][i] = i;
    
    for(int j=1; (1<<j) <= n; j++)
        for(int i = 0; i + (1<<j) - 1 < n; i++){
            if(a[M[j-1][i]] < a[M[j-1][i+(1<<(j-1))]]) M[j][i] = M[j-1][i];
            else M[j][i] = M[j-1][i+( 1<<(j-1) )];
        }
} 

int rmq(int i, int j){
    int k = log2(j-i+1);
    if(a[M[k][i]] <= a[M[k][j-(1 << k)+1]]) return M[k][i];
        else return M[k][j-(1 << k)+1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    preprocessing();
    
    int res = 0; int m,l,r;
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> l >> r;
        res += a[rmq(l,r)];
    }
    cout << res;
    return 0;
}