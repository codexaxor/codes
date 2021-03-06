#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000

int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}

struct node
{
	int gmax,gmin;
};

node t[400016];

void merges(int x,int y,int z)
{
	t[z].gmax=max(t[x].gmax,t[y].gmax);
	t[z].gmin=gcd(t[x].gmin,t[y].gmin);
}

node merge_res(node x,node y)
{
	node temp;
	temp.gmax=max(x.gmax,y.gmax);
	temp.gmin=gcd(x.gmin,y.gmin);
	return temp;
}

void build(int a[],int v,int l,int r)
{
	if(l==r)
	{
		t[v].gmax=a[l];
		t[v].gmin=a[l];
	}
	else
	{
		int m=(l+r)/2;
		build(a,2*v,l,m);
		build(a,2*v+1,m+1,r);
		merges(2*v,2*v+1,v);
	}
} 

node query(int v,int l,int r,int x,int y)
{
	if(x>y)
	{
		node null_node;
		
		null_node.gmin=0;
		null_node.gmax=0;
		
		return null_node;
	}
	else if(l==x&&r==y)
	return t[v];
	else
	{
		int m=(l+r)/2;
		node n1=query(2*v,l,m,x,min(m,y));
		node n2=query(2*v+1,m+1,r,max(x,m+1),y);
		node temp1;
		temp1=merge_res(n1,n2);
		return temp1;
	}
}


int main()
{
	int n,i,x,y,a[100002],pos,value,m,ans,id;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	build(a,1,0,n-1);
//	for(i=1;i<=7;i++)
//	cout<<t[i].sum<<"  ";
	while(m--)
	{
        	scanf("%d%d",&x,&y);
        	node ans;
			ans=query(1,0,n-1,x-1,y-1);
			printf("%d %d\n",ans.gmax,ans.gmin);
        
	}
	return 0;
}
