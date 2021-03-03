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

const ll MX=10005;

ll dist[MX];
ll sf[MX];


void sieve()
{
    for(int i=1;i<MX;i++)
        sf[i]=i;
    for(int i=4;i<MX;i+=2)
        sf[i]=2;
    for(int i=3;i*i<MX;i+=2)
    {
        if(sf[i]==i)
        {
            for(int j=i*i;j<MX;j+=2*i)
            {
                sf[j]=i;
            }
        }
    }
}

ll bfs(ll s,ll t)
{
    ms(dist,-1);
    queue<ll> q;
    q.push(s);
    dist[s]=0;
    while(!q.empty())
    {
        ll u= q.front();
        ll ff=u;
        q.pop();
        while(ff>1)
        {
            ll x=sf[ff];
            ff/=x;
            if(u+x>t || x==u || x==1)continue;
            if(dist[u+x]==-1 || dist[u+x]>dist[u]+1)
            {
                dist[x+u]=dist[u]+1;
                q.push(u+x);
            }
        }
    }
    return dist[t];
}

int main()
{
//    READ;
//    WRITE;
    IOS;
    sieve();
    int ts,cs=0;
    cin>>ts;
    while(ts--)
    {
        int s,t;
        cin>>s>>t;
        ll ans=bfs(s,t);
        cout<<"Case "<<++cs<<": "<<ans<<"\n";
    }
    return 0;
}
