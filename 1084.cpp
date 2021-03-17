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

ll a[MAX];
ll dp[MAX];

ll solve(int idx,int n,int K)
{
    if(idx==n)
    {
        return 0;
    }
    ll &ret=dp[idx];
    if(ret!=-1)return ret;
    ll LIM = lower_bound(a+idx,a+n,a[idx]+2*K)-a,ans=MOD;
    if(LIM-idx+1<3)return ret=ans;
    for(int i=LIM;i>=idx+2;i--)
    {
        if((a[i]-a[idx])<=2*K)
        ans=min(1+solve(i+1,n,K),ans);
    }
    return ret=ans;
//    for(int i=min(idx+3,LIM);i)
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
        ms(dp,-1);
        ll n,K;
        cin>>n>>K;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        ll ans=solve(0,n,K);
        if(ans>n)ans=-1;
        cout<<"Case "<<++cs<<": "<<ans<<"\n";
    }
    return 0;
}
