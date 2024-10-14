#include <bits/stdc++.h>
using namespace std;

#define MAX 10

int H, W;
int h[MAX + 1], w[MAX + 1];
int n;
bool visited[MAX + 1][MAX + 1];
int result = 0;

void input(){
    cin >> H >> W;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> h[i] >> w[i];
    }
}

bool check(int h, int w, int x, int y){
    if (x + h - 1 > H || y + w - 1 > W) {
        return false;
    }
    
    for(int i = x; i < x + h; i++){
        for(int j = y; j < y + w; j++){
            if(visited[i][j]) return false;
        }
    }
    return true;
}

void accept(int h, int w, int x, int y){
    for(int i = x; i < x + h; i++){
        for(int j = y; j < y + w; j++){
            visited[i][j] = true;
        }
    }
}

void unaccept(int h, int w, int x, int y){
    for(int i = x; i < x + h; i++){
        for(int j = y; j < y + w; j++){
            visited[i][j] = false;
        }
    }
}

void TRY(int k){
    if (k > n) {
        result = 1; 
        return;
    }
    
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(check(h[k], w[k], i, j)){
                accept(h[k], w[k], i, j);
                TRY(k+1);
                unaccept(h[k], w[k], i, j);
            }
            if(check(w[k], h[k], i, j)){
                accept(w[k], h[k], i, j);
                TRY(k + 1);
                unaccept(w[k], h[k], i, j);
            }
        }
    }
}

void solution(){
    input();
    memset(visited, false, sizeof(visited));
    TRY(1);
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solution();
    return 0;
}