#include <bits/stdc++.h>
#define ft(i,x,y) for(int i=x;i<=y;i++)
using namespace std;

int n,m;

long long c[5001], d[5001];

long long f[5001][5001];
vector <int> X[5001];
typedef struct pair<long long, long long> ii;
typedef struct pair<ii, int> iii;
priority_queue<iii, vector <iii>, greater<iii> > pri;
long long find_path(int start, int finish)
{
    ft(i,1,n)
    {
        ft(j,0,n)
        {
            f[i][j] = 1e18;
        }
    }
    f[start][d[start]] = c[start];
    pri.push(
        iii(
            ii(
                f[start][d[start]],
                d[start]
            ),
            start
        )
    );
    while(!pri.empty())
    {
        int u = pri.top().second;
        long long cost = pri.top().first.first;
        int remaining_des = pri.top().first.second;

        pri.pop();
        
        if(cost != f[u][remaining_des]) continue;
        if(u == finish) return cost;
        for(int v: X[u])
        {
            if(remaining_des > 0)
            {
                if(f[v][remaining_des - 1] > cost)
                {
                    f[v][remaining_des-1] = cost;
                    pri.push(
                        iii(
                            ii(
                                cost,
                                remaining_des - 1
                            ),
                            v
                        )
                    );
                }
                if(f[v][d[v]] > cost + c[v])
                {
                    f[v][d[v]] = cost + c[v];
                    pri.push(
                        iii(
                            ii(
                                cost + c[v],
                                d[v]
                            ),
                            v
                        )
                    );
                }
            }
        }
    }
    return -1;
}
int main()
{
    // freopen("./text.input","r",stdin);
    cin>>n>>m;
    ft(i,1,n)
    {
        cin>>c[i]>>d[i];
    }
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        X[a].push_back(b);
        X[b].push_back(a);
    }

    cout<<find_path(1, n);
    return 0;
}