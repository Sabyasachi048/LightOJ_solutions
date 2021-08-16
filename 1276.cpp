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
#define LIM             (ll)(1e12)
using namespace std;
using namespace __gnu_pbds;

vector<ll> lucky,vlucky;


void generate_lucky(ll sum)
{
    if(sum>LIM)return;
    if(sum>0)
    {
        lucky.push_back(sum);
    }
    generate_lucky(sum*10LL+4);
    generate_lucky(sum*10LL+7);
}



void generate_vlucky(ll sum,int idx,int &sz)
{
    if(sum>LIM || sum<=0)return;
    if(sum>1)
    {
        lucky.push_back(sum);
    }
    for(int i=idx; i<sz; i++)
    {
        ll x = lucky[i]*sum;
        if(x>0 && x<=LIM)
        {
            generate_vlucky(x,i,sz);
        }
        else break;

    }
}

int main()
{
//    READ;
//    WRITE;
    IOS;
    generate_lucky(0);
    sort(all(lucky));
    lucky.erase(unique(all(lucky)),lucky.end());
    int cc = lucky.size();
    generate_vlucky(1,0,cc);
    sort(all(lucky));
    lucky.erase(unique(all(lucky)),lucky.end());
    int ts,cs=0;
    cin>>ts;
    while(ts--)
    {
        ll x,y;
        cin>>x>>y;
        int up = upper_bound(all(lucky),y)-lucky.begin();
        int low = lower_bound(all(lucky),x)-lucky.begin();
        ll ans=up-low;
        cout<<"Case "<<++cs<<": "<<ans<<"\n";
    }
    return 0;
}
