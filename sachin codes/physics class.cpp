#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

// Input: Indices Range [l ... r)
// Invariant: A[l] <= key and A[r] > key
int GetRightPosition(int A[], int l, int r, int key)
{
    int m;
 
    while( r - l > 1 )
    {
        m = l + (r - l)/2;
 
        if( A[m] <= key )
            l = m;
        else
            r = m;
    }
 
    return l;
}
 
// Input: Indices Range (l ... r]
// Invariant: A[r] >= key and A[l] > key
int GetLeftPosition(int A[], int l, int r, int key)
{
    int m;
 
    while( r - l > 1 )
    {
        m = l + (r - l)/2;
 
        if( A[m] >= key )
            r = m;
        else
            l = m;
    }
 
    return r;
}
 
int CountOccurances(int A[], int size, int key)
{
    // Observe boundary conditions
    int left = GetLeftPosition(A, -1, size-1, key);
    int right = GetRightPosition(A, 0, size, key);
 
    // What if the element doesn't exists in the array?
    // The checks helps to trace that element exists
    return (A[left] == key && key == A[right])?
           (right - left + 1) : 0;
}
int a[10003];
int main()
{
	int t,n,i,j,c,h,y;
	int p,f,count,x,r;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&f);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		sort(a,a+n);
	   	//cout<<CountOccurances(a,2,2)<<endl;
		
		count=0;
		for(i=1;i<n;i++)
		{
			j=0;
			while(pow(f,j)<=a[i])
			{
				p=pow(f,j); 
				r=a[i]%p;                     
				
				if(r==0)
				{
					x=a[i]/p;
					c=CountOccurances(a,i,x);
					count+=c;
				}
				j++;
			}
		
		}
		printf("%d\n",count);
	}
	return 0;
}
