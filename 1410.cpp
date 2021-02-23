#include <bits/stdc++.h>
#define prt_cs                  printf("Case %d: ",cs)
#define sqr(x)                  (x)*(x)
#define ms(a,b)                 memset(a, b, sizeof(a))
#define db                      double
#define ll                      long long int
#define MOD                     100000007
#define PI                      acos(-1.0)
#define pii                     pair< int, int >
#define READ                    freopen("in.txt","r",stdin)
#define WRITE                   freopen("out.txt","w",stdout)
#define gcd(a, b)               __gcd(a, b)
#define lcm(a, b)               (((a)*(b))/gcd(a,b))
#define MAX                     100005

using namespace std;

int x[1001],y[1001];

int main()
{
//    READ;
//    WRITE;
    int ts;
    scanf("%d",&ts);
    for(int cs=1;cs<=ts;cs++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        scanf("%d %d",&x[i],&y[i]);
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
                {
                    v.push_back(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
                }
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        int ans=1+v.size();
        prt_cs;
        printf("%d\n",ans);
    }
    return 0;
}
