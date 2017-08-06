#include<bits/stdc++.h>

using namespace std;

int node, edge;

const int sz = 1e5+5;

const int INF = 1e9+5;

vector<int>adj_list[sz];

vector<int>cost[sz];

vector<int>path;

int dis[sz], par[sz];

struct nodes
{
    int u, w;

    nodes(){}

    nodes(int u, int w):u(u), w(w){}

    bool operator<(const nodes &p) const
    {
        return w>p.w;
    }
};

int dijkstra(int n)
{
    memset(dis, 1, sizeof(dis));
    memset(par, -1, sizeof(par));

    priority_queue<nodes>q;

    q.push(nodes(1,0));

    dis[1] = 0;

    while(!q.empty())
    {
        nodes top = q.top();
        q.pop();

        int u = top.u;

        if(u==n) return dis[n];

        for(int i=0; i<adj_list[u].size(); i++)
        {
            int v = adj_list[u][i];

            if(dis[v]>dis[u]+cost[u][i])
            {
                dis[v] = dis[u]+cost[u][i];
                par[v] = u;
                q.push(nodes(v, dis[v]));
            }
        }
    }
    return -1;
}

main()
{
    cin>>node>>edge;

    int flag=0;

    for(int i=0; i<edge; i++)
    {
        int u, v, w;

        cin>>u>>v>>w;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);

        cost[u].push_back(w);
        cost[v].push_back(w);
    }

    if(dijkstra(node)==-1)
    {
        puts("-1");
        return 0;
    }

    while(node!=-1)
    {
        path.push_back(node);
        node = par[node];
    }

    for(int i=path.size()-1; i>=0; i--) cout<<path[i]<<" ";
    cout<<endl;

    return 0;
}
