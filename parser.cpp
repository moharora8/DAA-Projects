#include<bits/stdc++.h>
using namespace std;

int i=0;
void B(string a)
{
	if(a[i]=='a'|| a[i]=='b')
	{
		i++;
		for(int j=i;j<a.length();j++)
		{
			cout<<a[j];
		}
		cout<<endl;
	}
	
}

void A(string a)
{
	B(a);
	if(a[i]=='c')
	{
		i++;
		for(int j=i;j<a.length();j++)
		{
			cout<<a[j];
		}
		cout<<endl; 
		//cout<<a<<endl;
	}
}

int main()
{
	string a="aa#";
	cout<<a<<endl;
	A(a);
	if(a[i]=='#')
	{
		cout<<"Possible string!!"<<endl;
	}
	else
	{
		cout<<"Not possible";
	}
	return 0;
}
