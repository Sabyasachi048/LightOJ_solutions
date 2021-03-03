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
#define MAX             (ll)(1e6+5)
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
    mark[1]=0;
    for(int i=4;i<MAX;i+=2)
        mark[i]=1;
    for(int i=3;i*i<MAX;i+=2)
    {
        if(!mark[i])
        {
            for(int j=i*i;j<MAX;j+=2*i)
                mark[j]=1;
        }
    }
    primes.emplace_back(2);
    for(int i=3;i<MAX;i+=2)
    {
        if(!mark[i])
            primes.emplace_back(i);
    }
}



bool isPrime(ll x)
{
    if(x==1)return 0;
    if(x<MAX)return !mark[x];
    for(int i=0;primes[i]*primes[i]<=x && i<primes.size();i++)
    {
        if(x%primes[i]==0)return 0;
    }
    return 1;
}

bool isSquarePrime(ll x)
{
    if(x>=0)
    {
        ll pp = sqrt(x);
        return isPrime(pp) &&  (pp*pp==x);
    }
    return 0;
}

ll nod(ll n)
{
    if(n==1)return 1;
    ll x=n,ans=1;
    for(int i=0;i<primes.size();i++)
    {
        if(primes[i]*primes[i]*primes[i]>x)
            break;
        ll cnt=0;
        while(x%primes[i]==0)
        {
            x/=primes[i];
            cnt++;
        }
        if(cnt)
        {
            ans*=(cnt+1);
        }
    }

    if(isPrime(x))
    {
        ans*=2LL;
    }
    else if(isSquarePrime(x))
    {
        ans*=3LL;
    }
    else if(x>1LL)
    {
        ans*=4LL;
    }
    return ans;
}

int main()
{
//    READ;
//    WRITE;
    IOS;
    sieve();
    ll ts,cs=0;
    cin>>ts;
    while(ts--)
    {
        ll n;
        cin>>n;
        ll ans=nod(n)-1;
        cs++;
        cout<<"Case "<<cs<<": "<<ans<<"\n";
    }
    return 0;
}
