#include<iostream>
#include<stdio.h>
using namespace std;

void multiply(long long int F[2][2], long long int M[2][2]);
 
void power(long long int F[2][2], long long int n);

/* function that returns nth Fibonacci number */
long long int fibonacci(long long int n)
{
  long long int F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}
 void power(long long int F[2][2], long long int n)
{
  if( n == 0 || n == 1)
      return;
  long long int M[2][2] = {{1,1},{1,0}};
 
  power(F, n/2);
  multiply(F, F);
 
  if (n%2 != 0)
     multiply(F, M);
}
 
void multiply(long long int F[2][2], long long int M[2][2])
{
  long long int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  long long int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  long long int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  long long int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
 
  F[0][0] = x%1000000007;
  F[0][1] = y%1000000007;
  F[1][0] = z%1000000007;
  F[1][1] = w%1000000007;
}

int main()
{
	int t;
	long long int n,m,x,y,z;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		x=fibonacci(m+2);
		y=fibonacci(n+1);
		z=x-y;
		if(z<0)
		z=z+1000000007;
		printf("%lld\n",z);
	}
	return 0;
}
