#include<bits/stdc++.h>
using namespace std;

long long mulmod(long long int a,long long int b,long long int c)
{
	long long int x=0,y=a%c;
	while(b>0)
	{
		if(b%2==1)
		{
			x=(x+y)%c;
		}
		y=(y+y)%c;
		b=b/2;
	}
	return x%c;
}

long long int modular_exponentiation(long long int a,long long int b,long long int c)
{
	long long int x=1,y=a;
	while(b>0)
	{
		if(b%2==1)
		{
			x= mulmod(x,y,c);
		}
		y= mulmod(y,y,c);
		b=b/2;
	}
	return x%c;
}



bool miller_rabin(long long p,int iteration)
{
	int i;
    if(p<2)
	{
        return false;
    }
    if(p!=2 && p%2==0)
	{
        return false;
    }
    long long int s=p-1;
    while(s%2==0)
	{
        s/=2;
    }
    for(i=0;i<iteration;i++)
	{
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=modular_exponentiation(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1)
		{
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0)
		{
            return false;
        }
    }
    return true;
}

int main()
{
	int t,i,x;
	long long int n,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n==2)
		printf("2\n");
		else
		{
			
		
		if(n%2==0)
		{
			n=n-1;
		}
		while(1)
		{
			x=miller_rabin(n,3);//cout<<x;
			if(x==1)
			{
				ans=n;
				break;
			}
			n=n-2;
		}
		printf("%lld\n",ans);}
	}
	return 0;
}
