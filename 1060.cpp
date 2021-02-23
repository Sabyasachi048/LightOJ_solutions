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

ll fact[25];
ll cnt[27];

int main()
{
//    READ;
//    WRITE;
    IOS;
    fact[0]=1;
    for(int i=1; i<25; i++)
        fact[i]=fact[i-1]*i;
    int ts,cs=0;
    cin>>ts;
    while(ts--)
    {
        ms(cnt,0);
        string s;
        ll n;
        cin>>s>>n;
        int ok=1;
        int len=s.size();
        for(int i=0; i<s.size(); i++)
        {
            cnt[s[i]-'a']++;
        }
        ll ff=fact[len];
        for(int i=0; i<26; i++)
        {
            ff/=fact[cnt[i]];
        }
        if(n>ff)
        {
            ok=0;
        }
            int out[len+2];
            ll sum=0,k=0;
        if(ok)
        {

            while(sum!=n)
            {
                sum=0;
                for(int i=0; i<26; i++)
                {
                    if(!cnt[i])continue;
                    cnt[i]--;
                    ll ss=fact[len-1-k];
                    for(int j=0; j<26; j++)
                        ss/=fact[cnt[j]];
                    sum+=ss;
                    if(sum>=n)
                    {
                        out[k++]=i;
                        n-=(sum-ss);
                        break;
                    }
                    cnt[i]++;
                }
            }
            for(int i=25; i>=0 && k<len; i--)
            {
                if(cnt[i])
                {
                    out[k++]=i;
                    cnt[i++]--;
                }
            }
        }
        cout<<"Case "<<++cs<<": ";
        if(ok)
        {

            for(int i=0; i<len; i++)
                cout<<(char)(out[i]+'a');
        }
        else cout<<"Impossible";
        cout<<"\n";
    }
    return 0;
}
