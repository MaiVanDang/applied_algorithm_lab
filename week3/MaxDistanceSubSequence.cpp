#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005

int T;
int N,C;
int a[MAXN];

bool check(int distance) {
    int sl = 1; 
    int point = a[1]; 

    while (true) {
        point += distance; 
        auto it = lower_bound(a + 1, a + 1 + N, point); 

        // Nếu không còn phần tử nào lớn hơn hoặc bằng point
        if (it == a + 1 + N) {
            return false;
        }

        sl++; // Tăng số lượng phần tử đã chọn

        // Nếu đã chọn đủ C phần tử
        if (sl >= C) {
            return true;
        }

        // Cập nhật point cho vòng lặp tiếp theo
        point = *it; // Chọn phần tử hiện tại
    }
}

int MaxDistance(){
    int l = 0;
    int r = a[N] - a[1];
    while(l<=r){
        int mid =l + (r - l)/2;
        if(check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N >> C;
        for(int i = 1; i <= N; i++) cin >> a[i];
        sort(a + 1, a + 1 + N);
        cout << MaxDistance() << endl;
    }
    return 0;
}