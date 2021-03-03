#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define ms(a,b)        memset(a,b,sizeof(a))
#define PI             acos(-1.0)
#define ll             long long int
#define pii            pair< int, int >
#define READ           freopen("in.txt","r",stdin)
#define WRITE          freopen("out.txt","w",stdout)
#define gcd(a,b)       __gcd(a,b)
#define lcm(a,b)       ((a)*(b))/gcd(a,b)
#define MAX             (int)(1e5+5)
#define MOD            (ll)(1e9+7)
#define IOS             ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define all(x)          x.begin(),x.end()
#define set_pbds(T)         tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

struct edge{
    int u,v,w;
    edge(){}
    edge(int _u,int _v,int _w)
    {
        u=_u,v=_v,w=_w;
    }
    bool operator<(const edge &p)const
    {
//        if(w==p.w)
//        {
//            if(u==p.u)
//            {
//                return v<p.v;
//            }
//            return u<p.u;
//        }
        return w<p.w;
    }
};


vector<edge> vv,taken;
vector<int> adj[501];
int dist[501],par[501];
ll mat[501][501];

int find_par(int u)
{
    if(par[u]==u)return u;
    return par[u]=find_par(par[u]);
}

void mst(int n)
{
    sort(all(vv));
    for(int i=0;i<n;i++)
        par[i]=i;
    int cnt=0;
    for(int i=0;i<vv.size();i++)
    {
        int u=find_par(vv[i].u);
        int v=find_par(vv[i].v);
        if(u!=v)
        {
            par[u]=v;
            taken.push_back(vv[i]);
            cnt++;
            if(cnt==n-1)break;
        }
    }
}

void bfs(int s)
{
    priority_queue<pii> q;
    q.push({0,s});
    dist[s]=0;
    while(!q.empty())
    {
        int u=q.top().second;
        ll cst=-q.top().first;
        q.pop();
        for(auto v: adj[u])
        {
            if(dist[v]==-1 || max(cst,mat[u][v])<dist[v])
            {
                dist[v]=max(cst,mat[u][v]);

                q.push({-dist[v],v});
            }
        }
    }
}

int main()
{
//    READ;
//    WRITE;
    IOS;
    int ts,cs=0;
    cin>>ts;
    while(ts--)
    {
        taken.clear();
        ms(mat,-1);
        vv.clear();
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
            adj[i].clear();
        for(int i=0;i<m;i++)
        {
            edge e;
            cin>>e.u>>e.v>>e.w;
            vv.push_back(e);
        }
        mst(n);
        for(int i=0;i<taken.size();i++)
        {
            int u=taken[i].u,v=taken[i].v,w=taken[i].w;
            adj[u].push_back(v);
            adj[v].push_back(u);
            mat[u][u]=mat[v][v]=0;
            mat[u][v]=mat[v][u]=w;
        }
        ms(dist,-1);
        int T;
        cin>>T;
        bfs(T);
        cout<<"Case "<<++cs<<":\n";
        for(int i=0;i<n;i++)
        {
            if(dist[i]!=-1)
                cout<<dist[i]<<"\n";
            else cout<<"Impossible\n";
        }
    }
    return 0;
}
