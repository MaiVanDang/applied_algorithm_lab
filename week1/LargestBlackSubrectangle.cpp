#include <bits/stdc++.h>
using namespace std;

int n, m;
int A[1000][1000];
int maxS;

void solve(int row[]) {
    stack<int> res;
    int top_value, S = 0;
    int j = 0;
    while (j < n) {
        if (res.empty() || row[res.top()] <= row[j]) {
            res.push(j++);
        } else {
            top_value = row[res.top()];
            res.pop();
            if (!res.empty()){
                S = top_value*(j-res.top()-1);
            } else S = top_value * j;
            maxS = max(S, maxS);
        }
    }
    while (!res.empty()) {
        top_value = row[res.top()];
        res.pop();
        if (!res.empty()){
            S = top_value*(j-res.top()-1);
        } else S = top_value * j;
        maxS = max(S, maxS);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            cin >> A[i][j];
    for (int i=1; i<m; i++)
        for (int j=0; j<n; j++)
            if (A[i][j]) A[i][j] = A[i-1][j] + 1;
            else A[i][j] = 0;
    // for (int i=0; i<m; i++){
    //     for (int j=0; j<n; j++)
    //         cout << A[i][j];
    //     cout << endl;
    // }
    for (int i=0;i<m;i++) {
       solve(A[i]); 
    }
    cout << maxS;
    return 0;
}