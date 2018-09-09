#include <stdio.h>
#include <string.h>

#include <queue>


using namespace std;
const int INF = 0x3f3f3f3f;
const int M=1e6+10;

bool used[M];

int dis[M];
int head_a[M],head_b[M];

typedef struct tagEdge{
    int from,to;
    int value;
    int next;

    tagEdge(){}
    tagEdge(int _from,int _to,int _value,int _next):
        from(_from),to(_to),value(_value),next(_next){}
}Edge;

typedef struct tagNode{
    int to;
    int value;

    tagNode(){}
    tagNode(int _to,int _value):
        to(_to),value(_value){}
    bool operator<(const tagNode &other)const{
        return value+dis[to]>other.value+dis[other.to];
    }
}Node;

Edge edges_a[M],edges_b[M];

int n,m;
int edges_num;

int src,des,k;

void init()
{
    edges_num=0;
    memset(head_a,-1,sizeof(head_a));
    memset(head_b,-1,sizeof(head_b));
}

void add_edge(Edge *p,int *hd,int x,int y,int c)
{
    p[edges_num]=Edge(x,y,c,hd[x]);
    hd[x]=edges_num;
}

void dij(int des,Edge* edge,int *head)
{
    memset(used,false,sizeof(used));
    for(int i=1;i<=n;i++)
        dis[i]=INF;
    dis[des]=0;

    priority_queue<Node> que;
    que.push(Node(des,0));
    for(int i=1;i<n;i++){
        while(!que.empty()&&used[que.top().to])
            que.pop();
        if(que.empty())
            break;

        Node now=que.top();
        que.pop();
        used[now.to]=true;

        for(int j=head[now.to];j+1;j=edge[j].next)
            if(!used[edge[j].to]&&dis[edge[j].to]>dis[now.to]+edge[j].value){
                dis[edge[j].to]=dis[now.to]+edge[j].value;
                que.push(Node(edge[j].to,0));
            }
    }
}

int a_star(int src,Edge *edge,int *head)
{
    priority_queue<Node> que;
    que.push(Node(src,0));

    while(!que.empty()){
        Node now=que.top();
        que.pop();
        if(now.to==des){
            if(!k)
                return now.value;
            --k;
        }

        for(int i=head[now.to];i+1;i=edge[i].next)
            que.push(Node(edge[i].to,now.value+edge[i].value));
    }
    return INF;
}

int main()
{
    while(~scanf("%d%d",&n,&m)){
        init();
        int t; 
        scanf("%d%d%d%d",&src,&des,&k, &t);
        while(m--){
            int x, y, c;
            scanf("%d%d%d",&x,&y,&c);
            add_edge(edges_a,head_a,x,y,c);
            add_edge(edges_b,head_b,y,x,c);
            ++edges_num;
        }

        dij(des,edges_b,head_b);
        if(dis[src]>=INF){
            puts("Whitesnake!");
            continue;
        }
        --k;
        int ans=a_star(src,edges_a,head_a);
        if(t >= ans)puts("yareyaredawa");
        else puts("Whitesnake!");
    }
    return 0;
}
