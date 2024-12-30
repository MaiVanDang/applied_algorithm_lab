#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+1;
int a[N], S[N];
int n, L1, L2, ans;

void input(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> L1 >> L2;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void solve(){
    deque<int> d;// luu tru chi so cac ung cu vien j tham gia vao viec xac dinh cac bai toan
                // con S(i)
    ans = 0;
    for(int i = 1; i <= n; i++){
        while(!d.empty() && d.front() < i - L2) d.pop_front();
        int j = i - L1;
        if(j >= 1){
            while(!d.empty() && S[d.back()] < S[j]) d.pop_back();
            d.push_back(j);
        }
        S[i] = a[i] + (d.empty() ? 0 : S[d.front()]);
        ans = max(ans,S[i]);
    }
    cout << ans;
}
void solveN2(){
	S[1] = a[1];ans = S[1];
	for(int i = 2; i <= n; i++){
		S[i] = a[i];
		for(int d = L1; d <= L2; d++){
			int j = i-d;
			if(j >= 1 && S[i] < S[j] + a[i])
				S[i] = S[j] + a[i];
		}
		ans = max(ans,S[i]);
	}
	cout << ans;
}
void genData(char* filename, int n, int L1, int L2, int M){
	srand(time(NULL));
	FILE* f = fopen(filename,"w");
	fprintf(f,"%d %d %d\n",n,L1,L2);
	for(int i = 1; i <= n; i++){
		int x = rand()% M + 1;
		fprintf(f,"%d ",x);
	}
	fclose(f);
}
int main(){
	//genData("test/6.txt",1000000,1,10000,100);
	//freopen("test/6.txt","r",stdin);
	input();
	solve();
	//solveN2();
	return 0;
}
