#include <bits/stdc++.h>
#define ft(i,x,y) for(int i = x; i<=y;i++)
using namespace std;

int n, m;
int num[100001], low[100001], cnt = 0;
int N = 0;
vector<int> X[100001]; // Danh sách kề cho đồ thị
vector<vector<int>> sccComponents; // Vector để lưu các thành phần liên thông mạnh

stack<int> st;

void run(int u) {
    num[u] = low[u] = ++cnt; // Đánh số và thiết lập low cho đỉnh u
    st.push(u); // Đưa đỉnh u vào ngăn xếp

    for (int v : X[u]) {
        if (num[v]) {
            low[u] = min(low[u], num[v]); // Cập nhật low[u]
        } else {
            run(v); // Gọi đệ quy cho v
            low[u] = min(low[u], low[v]); // Cập nhật low[u] sau khi quay lại
        }
    }

    // Nếu low[u] == num[u], u là đỉnh gốc của một thành phần liên thông mạnh
    if (low[u] == num[u]) {
        vector<int> component; // Vector để lưu thành phần liên thông
        int v;
        N++;
        do {
            v = st.top(); // Lấy đỉnh trên cùng của ngăn xếp
            st.pop(); // Loại bỏ đỉnh khỏi ngăn xếp
            low[v] = num[v] = 1e9; // Đánh dấu đỉnh này như đã xử lý
            component.push_back(v); // Thêm đỉnh vào thành phần
        } while (v != u);
        sccComponents.push_back(component); // Lưu thành phần vào danh sách
    }
}

int main() {
    cin >> n >> m; // Đọc số đỉnh và số cạnh
    while (m--) {
        int a, b;
        cin >> a >> b; // Đọc các cạnh
        X[a].push_back(b); // Thêm cạnh vào đồ thị
    }

    ft(i, 1, n) {
        if (!num[i]) run(i); // Gọi hàm run cho các đỉnh chưa được đánh số
    }

    // In ra số lượng thành phần liên thông mạnh
    cout << N << endl;

    // In ra các thành phần liên thông mạnh
    // for (const auto& component : sccComponents) {
    //     for (int vertex : component) {
    //         cout << vertex << " ";
    //     }
    //     cout << endl; // Xuống dòng sau mỗi thành phần
    // }

    return 0;
}