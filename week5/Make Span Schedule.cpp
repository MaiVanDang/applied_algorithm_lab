#include <bits/stdc++.h>
#define ft(i, x, y) for(int i = x;i<=y;i++)
using namespace std;

int n,m;
int duration[10001];

int in[10001], out[10001];
int arrived[10001];
int start_time[10001];

vector <int> X[10001];

bool check_valid_graph()
{
    bool isHasNoInp = false;
    int count = 0;
    ft(i,1,n)
    {
        count+= (in[i] == 0);
    }
    if(count == 0) isHasNoInp = true;

    if(isHasNoInp == true) return false;
    ft(i, 1, n)
    {
        if(arrived[i] != in[i] ) return false;
    }
    return true;
}

void DFS(int u)
{
    if(in[u] != arrived[u]) return;
    for(int v: X[u])
    {
        arrived[v]++;
        start_time[v] = max(start_time[v], start_time[u] + duration[u]);
        DFS(v);
    }
}
int main()
{
    // freopen("./text.input","r",stdin);
    cin>>n>>m;
    ft(i,1,n)
    {
        cin>>duration[i];
    }
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        X[a].push_back(b);
        in[b] ++;
        out[a] ++;
    }
    ft(i,1,n)
    {
        if(in[i] == 0)
        {
            DFS(i);
        }
    }

    if(check_valid_graph() == false)
    {
        cout<<-1;
    }
    else
    {
        int res = -1 ;
        ft(i,1,n)
        {
            res = max(res, start_time[i] + duration[i]);
        }
        cout<<res;
    }
    return 0;
}