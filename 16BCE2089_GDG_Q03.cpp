#include<iostream>
using namespace std;
int matrix[300][300];
void rotate(int M1,int N1,int M,int N,int K)
{
	M--; N--; M1--; N1--;
	int j=N1+1,i=M1,k=0;
	int temp=matrix[i][j];
	while((i!=M1 || j!=N1)&&(k!=K))
	{
		if((i==M1)&&(j<N)) { matrix[i][j]=matrix[i][j+1]; j++; }
		else
		if((i<M)&&(j==N)) { matrix[i][j]=matrix[i+1][j]; i++; }
		else
		if((i==M)&&(j>N1)) { matrix[i][j]=matrix[i][j-1]; j--; }
		else
		if((i>M1)&&(j==N1)) { matrix[i][j]=matrix[i-1][j]; i--; }
		k++;
	}
	matrix[i][j]=temp;
}
int main()
{
	int i,j,M,N,R;
	cin>>M>>N>>R;
	for(i=0;i<M;i++)
	for(j=0;j<N;j++)
	cin>>matrix[i][j];
	int m1=1,n1=1,m2=M,n2=N;
	if(M%2==0)
	while(m1+1<=m2)
	{
	
		rotate(m1++,n1++,m2--,n2--,2*(m2+n2-2));
	}
	else if(N%2==0)
	for(i=0;i<R;i++)
	{
		m1=1; n1=1; m2=M; n2=N;
		while(n1+1<=n2)
		{
			rotate(m1++,n1++,m2--,n2--,2*(m2+n2-2));
		}
	}
	cout<<endl;
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
