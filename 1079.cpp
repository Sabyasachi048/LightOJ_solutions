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
#define set_pbds(T)         tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

int a[101];
double pp[101];
int dp[2][100001];
long double cp[100001];

int main()
{
//    READ;
//    WRITE;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ts,cs=0;
    cin>>ts;
    while(ts--)
    {
        ms(dp,0);
        ms(cp,0.0);
        ms(a,0);
        long double P;
        int n;
        cin>>P>>n;
        ll sum=0;
        P=1.00-P;
        for(int i=0; i<n; i++)
        {
            cin>>a[i]>>pp[i];
            sum+=a[i];
            pp[i]=(1.00-pp[i]);
        }
//        cerr<<"sum: "<<sum<<"\n";
        int x=0;
        cp[0]=1;
        for(int i=0;i<=n;i++)
        {
            for(int j=sum;j>=a[i];j--)
            {
                    cp[j]=max(cp[j],(cp[j-a[i]])*pp[i]);

            }
            x^=1;
        }
        int ans=0;
        for(int i=sum;i>=0;i--)
        {
            if(cp[i]>=P)
            {
                ans=i;
                break;
            }
        }
        cout<<"Case "<<++cs<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}
