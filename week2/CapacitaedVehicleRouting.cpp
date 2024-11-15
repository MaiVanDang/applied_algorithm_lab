//Chapter 2 - Capacitaed Vehicle Routing
#include<bits/stdc++.h>
using namespace std;

#define max 12
#define MAX 5
#define oo 1e9

int n, K, Q, cmin = oo;
int d[max+1], c[max+1][max+1];
int x[max+1], y[max+1], load[max+1];
int visited[max+1];
int segments = 0, f = 0, fOpt = oo, nbR;

void input(){
    cin >> n >> K >> Q;
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            cin >> c[i][j];
            if (i != j) cmin = min(cmin,c[i][j]);
        }
    }
}

bool checkY(int v, int k){
    if(v == 0) return true;
    if(d[v] > Q) return false;
    if(visited[v]) return false;
    return true;
}

bool checkX(int v, int k){
    if (v > 0 && visited[v]) return false;
    if (load[k] + d[v] > Q) return false;
    return true;
}

void updateBest() {
	if (f < fOpt) fOpt = f;
}

void TRY_X(int s, int k){
    if(s == 0){
        if(k < K) TRY_X(y[k+1], k + 1);
        return;
    }
    
    for(int v = 0; v <= n; v++){
        if(checkX(v, k)){
            x[s] = v;
			visited[v] = true;
			f += c[s][v];
			segments++;
			load[k] += d[v];
			if (v > 0) {
				if (f + (n + nbR - segments) * cmin < fOpt)
					TRY_X(v, k);
			} else {
				if (k == K) {
					if (segments == n + nbR) updateBest();
				} else {
					if (f + (n + nbR - segments) * cmin < fOpt) 
						TRY_X(y[k + 1], k + 1);
				}
			}
			visited[v] = false;
			f -= c[s][v];
			segments--;
			load[k] -= d[v];
        }
    }
}

void TRY_Y(int k){
    int s = 0;
    if(y[k-1] > 0){
        s = y[k-1] + 1;
    }  
    
    for(int v = s; v <= n; v++){
        if(checkY(v,k)){
            y[k]=v;
            if(v > 0) segments++;
            f += c[0][v];
            visited[v] = true;
			load[k] += d[v];
			if (k < K) TRY_Y(k + 1);
			else {
			    nbR = segments; 
				TRY_X(y[1], 1);
			}
			if (v > 0) segments--;
			f -= c[0][v];
			visited[v] = false;
			load[k] -= d[v];
        }
    }
}

int main(){
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("data.inp", "r"))
		freopen("data.inp", "r", stdin);
	input();
	y[0] = 0; d[0] = 0; 
	TRY_Y(1);
	cout << fOpt << endl;
    return 0;
}