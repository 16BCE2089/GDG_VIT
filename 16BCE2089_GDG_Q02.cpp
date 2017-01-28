#include<iostream>
using namespace std;
int main()
{
	int j,T,Tarr[2500],temp,count1,count2,sum;
	char c,str[105];
	cin>>T;
	if((T<1)||(T>2500))
	{
		cout<<"Constraints breached";
		return 0;
	}
	for(int i=0;i<T;i++)
	{
		cin>>str;
		sum=0;
		count1=0; count2=0;
		for(j=0;str[j]!='\0';j++ )
		{
			if(str[j]==str[j+1])
			sum++;
			else if(str[j+1]=='\0')
			{
				sum++;
				if(count1<sum) count1=sum;
			}
			else if(str[j]!=str[j+1])
			{
				sum++;
				if(count1<sum) count1=sum;
				sum=0;
				temp=count1;
				count1=count2;
				count2=temp;
			}
		}
		if(count1<=count2) count2/=2;
		else count1/=2;
		if(count1>=count2) Tarr[i]=count1;
		else Tarr[i]=count2;
	}
	for(int i=0;i<T;i++)
		cout<<Tarr[i]<<endl;
	return 0;
}
