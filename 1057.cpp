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

char graph[21][21];
int dist[21][21];
int dp[21][(1<<16)+5];
vector<pii> nodes;


int solve(int g)
{
    for(int i=0;i<=g+1;i++)
    {
        for(int j=0;j<(1<<(g+1));j++)
            dp[i][j]=MOD;
    }
    dp[0][0]=0;
    queue<pii> q;
    q.push({0,0});
    while(!q.empty())
    {
        pii u=q.front();
        q.pop();
        for(int i=0;i<=g;i++)
        {
            if(i==u.first)
            {
                continue;
            }
            int nmask=u.second|(1<<i);
            if(dp[u.first][u.second]+dist[u.first][i]<dp[i][nmask])
            {
                dp[i][nmask]=dist[u.first][i]+dp[u.first][u.second];
                q.push({i,nmask});
            }
        }
    }
    return dp[0][(1<<(g+1))-1];
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
        ms(dist,0);
        int n,m,g=0,sx,sy;
        cin>>n>>m;
        nodes.clear();
        nodes.resize(20);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>graph[i][j];
                if(graph[i][j]=='g')
                {
                    nodes[++g]=make_pair(i,j);
                }
                else if(graph[i][j]=='x')
                {
                    sx=i,sy=j;
                    nodes[0]=make_pair(i,j);
                }
            }
        }
        for(int i=0;i<=g;i++)
        {
            for(int j=0;j<=g;j++)
            {
                dist[i][j]=dist[j][i]=max(abs(nodes[i].first-nodes[j].first),abs(nodes[i].second-nodes[j].second));
            }
        }
        int ans=solve(g+(g==0));
        cout<<"Case "<<++cs<<": "<<ans<<"\n";
    }
    return 0;
}
