#include<iostream>

using namespace std;
void display(int A[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<A[i];
	}
	cout<<endl;
}
int removeDuplicates(int A[], int n)
{
	if(n<=2) return n;
	int m = n;
	int duplicate = 1;
	for(int i=0;i<n-1;i++)
	{
		display(A,n);
		if(A[i] == A[i+1])
			duplicate++;
		else
			duplicate = 1;
		if(duplicate>2)
		{
			m--;
			duplicate--;
			for(int j = i+1;j<n-1;j++)
				A[j] = A[j+1];
		}
	}
	display(A,m);
	return m;
}
void main()
{
	int A[] = {1,1,1,1,3};
	int N = 5;
	cout<<removeDuplicates(A, N);
}