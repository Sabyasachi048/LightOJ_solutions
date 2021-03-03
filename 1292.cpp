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

vector<pii> pts;


int main()
{
//    READ;
//    WRITE;
    IOS;
    int ts,cs=0;
    cin>>ts;
    while(ts--)
    {
        pts.clear();
        int n;
        ll ans=1;
        cin>>n;
        pts.resize(n);
        for(int i=0; i<n; i++)
        {
            cin>>pts[i].first>>pts[i].second;
        }
        sort(all(pts));
        for(int i=0; i<n; i++)
        {
            map<pii,ll> mp;
            for(int j=i+1; j<n; j++)
            {
                ll yslope=(pts[j].second-pts[i].second);
                ll xslope=(pts[j].first-pts[i].first);
                ll g=gcd(abs(yslope),abs(xslope));
                yslope/=g;
                xslope/=g;
                pii xy=make_pair(yslope,xslope);
                if(mp[xy]==0)mp[xy]=1;
                mp[xy]++;
                ans=max(ans,mp[xy]);
            }
        }
        cout<<"Case "<<++cs<<": "<<ans<<"\n";
    }
    return 0;
}
