#include <bits/stdc++.h>
#define prt_cs                  printf("Case %d:\n",cs)
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
#define MAX                     30005

using namespace std;

int a[MAX],parent[MAX],depth[MAX],heavy[MAX],cur_pos,head[MAX],pos[MAX];
vector<int> adj[MAX];
int tree[4*MAX];


int dfs(int u)
{
    int mxc=0,sz=1;
    for(int i=0;i<adj[u].size();i++)
    {
        int v = adj[u][i];
        if(v!=parent[u])
        {
            parent[v]=u;
            depth[v]=depth[u]+1;
            int c= dfs(v);
            sz+=c;
            if(c>mxc)
            {
                mxc=c;
                heavy[u]=v;
            }
        }
    }
    return sz;
}

void decompose(int u,int h)
{
    head[u]=h;
    pos[u]=cur_pos++;
    if(heavy[u]!=-1)
        decompose(heavy[u],h);
    for(int i=0;i<adj[u].size();i++)
    {
        int c = adj[u][i];
        if(c!=parent[u] && heavy[u]!=c)
        {
            decompose(c,c);
        }
    }
}

void update(int node,int b,int e,int i,int val)
{
    if(b>e || b>i || e<i)return;
    if(b>=i && e<=i)
    {
        tree[node]=val;
        return;
    }
    int left=node<<1,right=left+1,mid=(b+e)/2;
    update(left,b,mid,i,val);
    update(right,mid+1,e,i,val);
    tree[node]=tree[left]+tree[right];
}

int query(int node,int b,int e,int i,int j)
{
    if(b>e || b>j || e<i)return 0;
    if(b>=i && e<=j)
        return tree[node];
    int left=node<<1,right=left+1,mid=(b+e)/2;
    int r1,r2;
    r1=query(left,b,mid,i,j);
    r2=query(right,mid+1,e,i,j);
    return r1+r2;
}

int graph_query(int a,int b,int n)
{
    int res=0;
//    cerr<<"cur: ";
    for(;head[a]!=head[b];b = parent[head[b]])
    {
        if(depth[head[a]]>depth[head[b]])
            swap(a,b);
        int cur_heavy = query(1,1,n,pos[head[b]]+1,pos[b]+1);
//        cerr<<cur_heavy<<" ";
        res+=cur_heavy;
    }
//    cerr<<endl;
    if(depth[a]>depth[b])swap(a,b);
    int last_heavy=query(1,1,n,pos[a]+1,pos[b]+1);
    res+=last_heavy;
    return res;
}

int main()
{
//    READ;
//    WRITE;
    int ts,cs=0;
    scanf("%d",&ts);
    while(ts--)
    {
        ms(tree,0);
        cur_pos=0;
        ++cs;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            adj[i].clear();
            parent[i]=0;
            depth[i]=0;
            heavy[i]=-1;
            pos[i]=0;
            head[i]=0;
        }
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0);
//        cerr<<"pass 1\n";
//        for(int i=0;i<n;i++)
//            cerr<<heavy[i]<<" ";

        decompose(0,0);
//        cerr<<"pass 2\n";
//        for(int i=0;i<n;i++)
//            cerr<<head[i]<<" ";
//        cerr<<endl;
//        cerr<<"pos: ";
//        for(int i=0;i<n;i++)
//            cerr<<pos[i]<<" ";
//        cerr<<endl;
        for(int i=0;i<n;i++)
        {
            update(1,1,n,pos[i]+1,a[i]);
//            cerr<<tree[1]<<" ";
        }
//        cerr<<endl;
//        cerr<<"pass 3\n";
        int q;
        scanf("%d",&q);
        prt_cs;
        while(q--)
        {
            int ch,x,y;
            scanf("%d %d %d",&ch,&x,&y);
            if(ch==1)
            {
                update(1,1,n,pos[x]+1,y);
            }
            else
            {
                int ans=graph_query(x,y,n);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
