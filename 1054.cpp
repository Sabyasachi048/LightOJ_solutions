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
#define MAX             (int)(1e6+5)
#define MOD            (ll)(1e9+7)
#define IOS             ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define all(x)          x.begin(),x.end()
#define set_pbds(T)         tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

bool mark[MAX];
vector<ll> primes;

void sieve()
{
    for(int i=4; i<MAX; i+=2)
        mark[i]=1;
    for(ll i=3; i*i<MAX; i+=2)
    {
        if(!mark[i])
        {
            for(ll j=i*i; j<MAX; j+=2*i)
            {
                mark[j]=1;
            }
        }
    }
    primes.emplace_back(2);
    for(int i=3; i<MAX; i+=2)
    {
        if(!mark[i])
        {
            primes.emplace_back(i);
        }
    }
}

ll bigmod(ll n,ll p,ll M)
{
    ll res=1LL;
    ll a=n;
    while(p>0)
    {
        if(p&1LL)
        {
            res*=a;
            res%=M;
        }
        a=a*a;
        a%=M;
        p>>=1LL;
    }
    return res%M;
}

ll sod(ll n,ll m)
{
    ll x=n,ans=1;
    for(int i=0; primes[i]*primes[i]<=n && i<primes.size(); i++)
    {
        ll cnt=0;
        while(x%primes[i]==0)
        {
            x/=primes[i];
            cnt++;
        }
        if(cnt)
        {
            cnt*=m;
            ans*=(bigmod(primes[i],cnt+1,MOD)+MOD-1)%MOD;
            if(ans>=MOD)
                ans%=MOD;
            ans*=(bigmod(primes[i]-1,MOD-2,MOD))%MOD;
            if(ans>=MOD)
                ans%=MOD;
        }
    }
    if(x>=2)
    {
        ans*=((bigmod(x,m+1,MOD)+MOD-1)%MOD);
        if(ans>=MOD)
            ans%=MOD;
        ans*=(bigmod(x-1,MOD-2,MOD))%MOD;
        if(ans>=MOD)
            ans%=MOD;
    }
    return ans%MOD;
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
        ll n,m;
        cin>>n>>m;
        ll ans=sod(n,m);
        cout<<"Case "<<++cs<<": "<<ans<<"\n";
    }
    return 0;
}
