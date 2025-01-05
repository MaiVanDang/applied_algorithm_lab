//Cut material 3D3D
#include <bits/stdc++.h>
using namespace std;

// Lưu trữ kết quả tối ưu cho mỗi trạng thái
map<tuple<int, int, int>, int> dp;
// Lưu các kích thước mong muốn
vector<tuple<int, int, int>> desired;

// Kiểm tra xem kích thước hiện tại có phù hợp với yêu cầu không
bool isDesiredSize(int l, int w, int h) {
    for (auto &size : desired) {
        // Kiểm tra tất cả các cách xoay có thể
        if ((l == get<0>(size) && w == get<1>(size) && h == get<2>(size)) ||
            (l == get<0>(size) && w == get<2>(size) && h == get<1>(size)) ||
            (l == get<1>(size) && w == get<0>(size) && h == get<2>(size)) ||
            (l == get<1>(size) && w == get<2>(size) && h == get<0>(size)) ||
            (l == get<2>(size) && w == get<0>(size) && h == get<1>(size)) ||
            (l == get<2>(size) && w == get<1>(size) && h == get<0>(size))) {
            return true;
        }
    }
    return false;
}

// Hàm đệ quy tìm thể tích lãng phí tối thiểu
int solve(int l, int w, int h) {
    // Nếu khối đá có kích thước mong muốn
    if (isDesiredSize(l, w, h)) {
        return 0;
    }
    
    // Kiểm tra cache
    auto state = make_tuple(l, w, h);
    if (dp.count(state)) {
        return dp[state];
    }
    
    // Thể tích hiện tại
    int volume = l * w * h;
    // Khởi tạo kết quả là lãng phí toàn bộ khối
    int result = volume;
    
    // Thử cắt theo chiều dài
    for (int i = 1; i < l; i++) {
        int waste = solve(i, w, h) + solve(l - i, w, h);
        result = min(result, waste);
    }
    
    // Thử cắt theo chiều rộng
    for (int i = 1; i < w; i++) {
        int waste = solve(l, i, h) + solve(l, w - i, h);
        result = min(result, waste);
    }
    
    // Thử cắt theo chiều cao
    for (int i = 1; i < h; i++) {
        int waste = solve(l, w, i) + solve(l, w, h - i);
        result = min(result, waste);
    }
    
    dp[state] = result;
    return result;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int L, W, H, N;
        cin >> L >> W >> H;
        cin >> N;
        
        // Reset các biến toàn cục
        dp.clear();
        desired.clear();
        
        // Đọc các kích thước mong muốn
        for (int i = 0; i < N; i++) {
            int l, w, h;
            cin >> l >> w >> h;
            desired.push_back(make_tuple(l, w, h));
        }
        
        // In kết quả
        cout << solve(L, W, H) << endl;
    }
    
    return 0;
}