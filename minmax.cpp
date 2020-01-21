#include<bits/stdc++.h>
using namespace std;

int* minmax(int a[],int low,int high)
{
	int mid;
	//b[0] for minimum
	//b[1] for maximum
	int* b=new int[2];
	//c[0] for minimum for left side of mid
	//c[1] for maximum for left side of mid
	int* c=new int[2];
	//d[0] for minimum for right side of mid
	//d[1] for maximum for right side of mid
	int* d=new int[2];
	if(low==high)
	{
		b[0]=a[low];
		b[1]=a[high];
		return b;
	}
	if(high==low+1)
	{
		if(a[low]>a[high])
		{
			b[1]=a[low];
			b[0]=a[high];
		}
		else
		{
			b[0]=a[low];
			b[1]=a[high];
		}
		return b;
	}
		mid=(low+high)/2;
		c=minmax(a,low,mid);	//left of mid
		cout<<"C:"<<c[0]<<"\t"<<c[1]<<endl;
		d=minmax(a,mid+1,high);	//right of mid
		cout<<"D:"<<d[0]<<"\t"<<d[1]<<endl;
		if(c[0]<d[0])
		{
			b[0]=c[0];
		}
		else
		{
			b[0]=d[0];
		}

		if(c[1]>d[1])
		{
			b[1]=c[1];
		}
		else
		{
			b[1]=d[1];
		}

	return b;
}

int main()
{
	int* res=new int[2];
	int arr[5]={2,3,4,5,1};	
	//int n=sizeof(arr)/sizeof(arr[0]);
	res=minmax(arr,0,4);
	cout<<endl<<"Min:"<<res[0]<<endl;
	cout<<"Max:"<<res[1]<<endl;
	return 0;
}