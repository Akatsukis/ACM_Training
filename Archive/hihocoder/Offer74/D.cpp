#include<cstdio>
#include<iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
struct node{
	int v,id;
	node(int a,int b){v=a;id=b;}
	bool operator >(node b) const
	{return v==b.v?id>b.id:v<b.v;}
};
tree<node,null_type,greater<node>,rb_tree_tag,tree_order_statistics_node_update> T,TE;
int main(){
	int n,m,k,s=0,q,ans=0;
	char c[10];
	scanf("%d%d",&n,&m);
	while(n--){
        
	}
	printf("%d\n",ans);
	return 0;
}
