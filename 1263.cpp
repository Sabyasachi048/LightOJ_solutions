#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define ms(a,b)        memset(a,b,sizeof(a))
#define PI             acos(-1.0)
#define ll             long long int
#define pii            pair< ll, ll >
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

ll c[1001];
vector<int> adj[1001];
bool visited[1001];

pii bfs(ll s)
{
    ll sum=c[s],nodes=1;
    queue<int> q;
    q.push(s);
    visited[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v: adj[u])
        {
            if(!visited[v])
            {
                visited[v]=1;
                sum+=c[v];
                nodes++;
                q.push(v);
            }
        }
    }
    return make_pair(sum,nodes);
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
        int n,m;
        cin>>n>>m;
        ll sum=0;
        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
            visited[i]=0;
            cin>>c[i];
            sum+=c[i];
        }
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout<<"Case "<<++cs<<": ";
        if(sum%n==0)
        {
            ll avg=sum/n;
            int ok=1;
            for(int i=1;i<=n;i++)
            {
                if(!visited[i])
                {
                    pii ff=bfs(i);
                    ll m=ff.first/ff.second;
                    if(ff.first%ff.second!=0 || m!=avg)
                    {
                        ok=0;
                        break;
                    }
                }
            }
            if(ok)cout<<"Yes\n";
            else cout<<"No\n";
        }
        else{
            cout<<"No\n";
        }

    }
    return 0;
}
