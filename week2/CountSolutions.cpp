#include<bits/stdc++.h>

using namespace std;

const int MAX_LENGHT = 1e6;
int n,M;
int a[MAX_LENGHT], x[MAX_LENGHT];
int t[MAX_LENGHT];

int f;
int Count = 0;



void nhapso(){
    cin >> n >> M;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        t[i] = t[i-1] + a[i];
    }
}

void solution() {
    if (f == M) {
        Count++;
    }
}

void TRY(int k) {
    int v;
    for (v = 1; v <= (M - f - (t[n] - t[k])) / a[k]; v++) {
        x[k] = v;
        f += a[k] * x[k];
        if (k == n) {
            solution();
        } else {
            TRY(k + 1);
        }
        f -= a[k] * x[k];
    }
}



void solve(){
    f = 0;
    t[0] = 0;
    nhapso();
    TRY(1);
    cout << Count;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    solve();
    
    return 0;
}
